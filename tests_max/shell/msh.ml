open Msh_ast


let parse_inputunit lb =
  Msh_parser.inputunit Msh_lexer.token lb

let print_prompt () =
  let pwd = Unix.getcwd () in
  let dernier_slash s =
    let rec aux i = match s.[i] with
      | '/' -> i
      | _   -> aux (i-1)
    in aux (String.length s - 1) in
  let pos = dernier_slash pwd in
  let n = String.length pwd in
  let pwd_short = (String.sub pwd (pos + 1) (n - pos - 1)) ^ "/" in
  print_string pwd_short;
  print_string " --> ";
  flush stdout

let step lb =
  print_prompt ();
  let cmd = parse_inputunit lb in
  let n = Msh_evaluator.eval_cmd cmd in
  Format.eprintf "@.exit %u@." n


let main =
  let lb = Lexing.from_channel stdin in
  while true do
    try step lb with
    | Msh_lexer.Lexical_error s ->
        flush stdout;
        Format.eprintf "lexical error: %s\n@." s
    | Parsing.Parse_error ->
        flush stdout;
        Format.eprintf "syntax error\n@."
    | e ->
        Format.eprintf "error: %s\n@." (Printexc.to_string e)
  done
