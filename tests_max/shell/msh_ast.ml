type command =
  | Nothing
  | Simple_command of simple_command
  | If of command * command * command
  | Connection of command * connector * command

and simple_command =
    { cmd_line: string list;
      cmd_redirects: redirect list;
      cmd_bg: bool; }

and redirect =
  | Input of string          (** < file  *)
  | Output of string         (** > file  *)
  | Output_append of string  (** >> file *)

and connector =
  | Seq     (** ;  *)
  | And     (** && *)
  | Or      (** || *)
  | Pipe    (** |  *)
