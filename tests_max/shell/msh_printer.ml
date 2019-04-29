open Msh_ast

let fprint_connector ff op =
  match op with
  | Seq -> Format.fprintf ff ";"
  | And -> Format.fprintf ff "&&"
  | Or -> Format.fprintf ff "||"
  | Pipe -> Format.fprintf ff "|"

let fprint_redirect ff red =
  match red with
  | Input w -> Format.fprintf ff "< %s " w
  | Output w -> Format.fprintf ff "> %s " w
  | Output_append w -> Format.fprintf ff ">> %s " w

let rec fprint_simple_cmd ff cmd =
  List.iter
    (fun w -> Format.fprintf ff "\"%s\" " (String.escaped w))
    cmd.cmd_line;
  fprint_cmd_redirects ff cmd.cmd_redirects;
  if cmd.cmd_bg then Format.fprintf ff "& "
  else ()

and fprint_cmd_redirects ff cmd_redirects =
  List.iter (fun red -> fprint_redirect ff red) cmd_redirects


let rec fprint_cmd ff cmd =
  begin match cmd with
  | Nothing ->
      Format.fprintf ff ""
  | Simple_command scmd ->
      fprint_simple_cmd ff scmd
  | If (cmd, cmd1, cmd2) ->
      Format.fprintf ff "if@\n  @[%a@]@\n" fprint_cmd cmd;
      Format.fprintf ff "then@\n  @[%a@]@\n" fprint_cmd cmd1;
      Format.fprintf ff "else@\n  @[%a@]@\n" fprint_cmd cmd2;
      Format.fprintf ff "fi "
  | Connection (cmd1, op, cmd2) ->
      Format.fprintf ff "{@\n  @[%a%a@ %a@]@\n} "
        fprint_cmd cmd1
        fprint_connector op
        fprint_cmd cmd2
  end



let print cmd =
  Format.printf "%a@." fprint_cmd cmd
