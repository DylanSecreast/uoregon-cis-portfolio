(* Dylan Secreast
 * CIS 425 - Assignment #7
 * 11/21/16
 *)

 (*  Original skeleton file by Geoffrey Smith - http://users.cs.fiu.edu/~smithg/ *)

use "parser.sml";


datatype result =
    RES_ERROR of string
  | RES_NUM   of int
  | RES_BOOL  of bool
  | RES_SUCC
  | RES_PRED
  | RES_ISZERO
  | RES_FUN   of (string * term)
  | RES_CLOSURE of ((string * term) * env)
    and env = Env of (string * term) list;

exception not_found;

fun new_env() = Env(nil);
fun extend_env (Env(oldenv), id, value) = Env( (id, value):: oldenv);
fun extend_env_all (Env(oldenv), id_value_list) = Env(id_value_list @ oldenv);
fun lookup_env (Env(nil), id) = (print("Free Var!! "^id); raise not_found)
   |lookup_env (Env((id1,value1)::b), id) =
        if (id1 = id)
        then value1
	    else lookup_env(Env(b), id) ;


(* Call-by-name parameter passing with static scope
 * interp_lazy_static (term * env) -> result
*)
fun interp (exp, env) =

  case exp of
    AST_ERROR s                 => RES_ERROR s
  | AST_NUM  x                  => RES_NUM x
  | AST_BOOL b                  => RES_BOOL b
  | AST_SUCC                    => RES_SUCC
  | AST_PRED                    => RES_PRED
  | AST_ISZERO                  => RES_ISZERO
  | AST_IF (exp1, exp2, exp3)   => (case (interp (exp1, env)) of
        RES_BOOL true => interp (exp2, env)
      | RES_BOOL false => interp (exp3, env)
      | RES_ERROR s => RES_ERROR s
      | _ => RES_ERROR "Arg to if is not a bool.")
  | AST_APP (exp1, exp2)        => (case (interp (exp1, env)) of
        RES_SUCC => (case (interp (exp2, env)) of
            RES_NUM n => RES_NUM (n+1)
          | RES_ERROR s => RES_ERROR s
          | _ => RES_ERROR "Type error: attempted to take succ of non-number.")
      | RES_PRED => (case (interp (exp2, env)) of
            RES_NUM n => RES_NUM (n-1)
          | RES_ERROR s => RES_ERROR s
          | _ => RES_ERROR "Type error: attempted to take pred of non-number.")
      | RES_ISZERO => (case (interp (exp2, env)) of
            RES_NUM 0 => RES_BOOL true
          | RES_NUM n => RES_BOOL false
          | RES_ERROR s => RES_ERROR s
          | _ => RES_ERROR "Type error: attempted to take isZero of non-number.")
      | RES_CLOSURE (function, static_env)  =>
          let
            val (var, exp) = function
            val v1 = interp (exp2, env)
            val nenv = extend_env (static_env, var, v1)
            in interp (exp, nenv) end
          (*let
            val (var, exp) = function
            val v1 = interp (exp2, env)
          in case v1 of
              RES_ERROR s => v1
            | _ => let val nenv = extend_env (static_env, var, v1)
                   in interp (exp, nenv) end
          end*)
      | _ => RES_ERROR "Not yet implemented")
  | AST_ID name                 => interp(lookup_env(env, name), env)
  | AST_FUN  (var, exp)         => RES_CLOSURE ((var, exp), env)
  | AST_LET (var, exp1, exp2)   =>
      let val nenv = extend_env(env, var, exp1)
      in interp (exp2, nenv) end
  | AST_REC (var,exp)           => RES_ERROR "support for recursive bindings is not required for this assignment"
