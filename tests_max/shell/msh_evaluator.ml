open Msh_ast


let exec_simple_cmd cmd =
  let line, redirects, bg = cmd.cmd_line, cmd.cmd_redirects, cmd.cmd_bg in 
    match line with
      | "cd" :: dir :: _ ->
          Unix.chdir dir;
          0
      | "cd" :: [] ->
          let home = 
            try Unix.getenv "HOME"
            with Not_found -> assert false
          in
          Unix.chdir home;
          0
      | "pwd" :: [] ->
          print_string ((Unix.getcwd ())^"\n"); 0
      | "rmdir" :: dir :: _ ->
          Unix.rmdir dir; 0
      | _ ->
          let argv = Array.of_list line in
          Unix.handle_unix_error (Unix.execvp argv.(0)) argv; 0

let rec eval_cmd cmd =
  match cmd with
  | Nothing -> 0
  | Simple_command scmd ->
      exec_simple_cmd scmd
  | _ ->
      assert false (* XXX TODO XXX *)
