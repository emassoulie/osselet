/* Code écrit à partir du code source de bash. */

%{

open Msh_ast;;

let not_implemented s = failwith ("not implemented: "^s)

type simple_command_element =
    Elt_word of string
  | Elt_redi of redirect

let make_simple_command elt cmd =
  match elt with
  | Elt_word w ->
      { cmd with cmd_line = w :: cmd.cmd_line; }
  | Elt_redi redi ->
      { cmd with cmd_redirects = redi :: cmd.cmd_redirects }

let clean_simple_command cmd =
  Msh_misc.first_word := true;
  { cmd_line = List.rev cmd.cmd_line;
    cmd_redirects = List.rev cmd.cmd_redirects;
    cmd_bg = cmd.cmd_bg; }

let rec make_async cmd =
  match cmd with
  | Nothing -> Nothing
  | Simple_command scmd -> Simple_command { scmd with cmd_bg = true; }
  | If _ -> not_implemented "if asynchrone"
  | Connection (cmd1, connector, cmd2) ->
      Connection (cmd1, connector, make_async cmd2)

%}

%token IF THEN ELSE ELIF FI

%token LESS
%token GREATER GREATER_GREATER

%token AND AND_AND NEWLINE OR_OR BAR SEMI
%token EOF


%token <string> WORD


/* Précédence et associativité */

%left AND SEMI NEWLINE EOF
%left AND_AND OR_OR
%right BAR

/* Point d'entrée */

%start inputunit
%type <Msh_ast.command> inputunit


%%

inputunit:
  simple_list simple_list_terminator
    { $1 }
| NEWLINE
    { Nothing }
| EOF
    { Format.eprintf "Bye!@."; exit 0 }
;

redirection:
  GREATER WORD
    { Output $2 }
| LESS WORD
    { Input $2 }
| GREATER_GREATER WORD
    { Output_append $2 }
;

simple_command_element:
  WORD
    { Elt_word $1 }
| redirection
    { Elt_redi $1 }
;

simple_command:
  simple_command_element
    { match $1 with
      | Elt_word w ->
          { cmd_line = [w];
            cmd_redirects = [];
            cmd_bg = false; }
      | Elt_redi r ->
          { cmd_line = [];
            cmd_redirects = [r];
            cmd_bg = false; }
    }
| simple_command simple_command_element
    { make_simple_command $2 $1 }
;

command:
  simple_command
    { Simple_command (clean_simple_command $1) }
| shell_command
    { Msh_misc.first_word := true; $1 }
;

shell_command:
  if_command
    { $1 }
;

if_command:
  IF compound_list THEN compound_list FI
    { If ($2, $4, Nothing) }
| IF compound_list THEN compound_list ELSE compound_list FI
    { If ($2, $4, $6) }
| IF compound_list THEN compound_list elif_clause FI
    { If ($2, $4, $5) }
;

elif_clause:
  ELIF compound_list THEN compound_list
    { If ($2, $4, Nothing) }
| ELIF compound_list THEN compound_list ELSE compound_list
    { If ($2, $4, $6) }
| ELIF compound_list THEN compound_list elif_clause
    { If ($2, $4, $5) }
;

list:
  newline_list list0
    { $2 }
;

compound_list:
  list
    { $1 }
| newline_list list1
    { $2 }
;

list0:
  list1 NEWLINE newline_list
    { $1 }
| list1 AND newline_list
    { make_async $1 }
| list1 SEMI newline_list
    { $1 }
;

list1:
  list1 AND_AND newline_list list1
    { Connection ($1, And, $4) }
| list1 OR_OR newline_list list1
    { Connection ($1, Or, $4) }
| list1 AND newline_list list1
    { let cmd = make_async $1 in
      Connection (cmd, Seq, $4)
    }
| list1 SEMI newline_list list1
    { Connection ($1, Seq, $4) }
| list1 NEWLINE newline_list list1
    { Connection ($1, Seq, $4) }
| pipeline_command
    { $1 }
;

simple_list_terminator:
  NEWLINE
    { () }
| EOF
    { () }
;

newline_list:
  /* empty */
    { () }
| newline_list NEWLINE
    { () }
;

simple_list:
  simple_list1
    { $1 }
| simple_list1 AND
    { make_async $1 }
| simple_list1 SEMI
    { $1 }
;

simple_list1:
  simple_list1 AND_AND newline_list simple_list1
    { Connection ($1, And, $4) }
| simple_list1 OR_OR newline_list simple_list1
    { Connection ($1, Or, $4) }
| simple_list1 AND simple_list1
    { let cmd = make_async $1 in
      Connection (cmd, Seq, $3)
    }
| simple_list1 SEMI simple_list1
    { Connection ($1, Seq, $3) }
| pipeline_command
    { $1 }
;

pipeline_command:
  pipeline
    { $1 }
;

pipeline:
  pipeline BAR newline_list pipeline
    { Connection ($1, Pipe, $4) }
| command
    { $1 }
;
