{
  open Lexing
  open Msh_ast
  open Msh_parser

  exception Lexical_error of string

  let keyword_of_string =
    let h = Hashtbl.create 17 in
    List.iter (fun (s,k) -> Hashtbl.add h s k)
      [
        "if", IF;
        "then", THEN;
        "else", ELSE;
        "elif", ELIF;
        "fi", FI;
      ];
    fun s ->
      Msh_misc.first_word := false;
      try Some (Hashtbl.find h s) with Not_found -> None

  let newline lexbuf =
    let pos = lexbuf.lex_curr_p in
    lexbuf.lex_curr_p <-
      { pos with pos_lnum = pos.pos_lnum + 1; pos_bol = pos.pos_cnum }

}

rule token = parse
  | '#'
      { comment lexbuf; token lexbuf }
  | '\n'
      { newline lexbuf; NEWLINE }
  | [' ' '\t' '\r']+
      { token lexbuf }
  | '<'
      { LESS }
  | '>'
      { GREATER }
  | ">>"
      { GREATER_GREATER }
  | '&'
      { AND }
  | "&&"
      { AND_AND }
  | "||"
      { OR_OR }
  | '|'
      { BAR }
  | ';'
      { SEMI }
  | ( [^ '\n' ' ' '\t' '\r' '<' '>' '&' '|' ';' '"' ] | '\\' _ )+
      { let s = (lexeme lexbuf) in
        match !Msh_misc.first_word, keyword_of_string s with
        | true, Some kw -> kw
        | _ ->
            let lb = Lexing.from_string s in
            let buf = Buffer.create 512 in
            word buf lb;
            WORD (Buffer.contents buf) }
  | "\""
      { let buf = Buffer.create 512 in
        double_quote buf lexbuf;
        WORD (Buffer.contents buf) }
  | eof
      { EOF }
  | _
      { assert false }

and word buf = parse
  | [ '\n' ' ' '\t' '\r' '<' '>' '&' '|' ';' ]
      { assert false }
  | "\""
      { double_quote buf lexbuf;
        word buf lexbuf }
  | '\\' (_ as c)
      { Buffer.add_char buf c;
        word buf lexbuf }
  | eof
      { () }
  | _
      { Buffer.add_string buf (lexeme lexbuf);
        word buf lexbuf }

and double_quote buf = parse
  | '\n'
      { newline lexbuf;
        Buffer.add_string buf "\n";
        double_quote buf lexbuf }
  | "\""
      { () }
  | "\\\""
      { Buffer.add_string buf "\"";
        double_quote buf lexbuf }
  | '\\' _
      { Buffer.add_string buf (lexeme lexbuf);
        double_quote buf lexbuf }
  | [^ '\\' '\"' '\n']+
      { Buffer.add_string buf (lexeme lexbuf);
        double_quote buf lexbuf }
  | eof
      { raise (Lexical_error "unterminated string") }

and comment = parse
  | '\n'
      { newline lexbuf }
  | _
      { comment lexbuf }
