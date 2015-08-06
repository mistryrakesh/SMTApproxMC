# README #

ApproxMC for SMT Solvers.

### Files changed in CVC4 ###

  1. src/expr/command.cpp (line 999)  
     Added function:  
     `Expr GetModelCommand::getModelCommandInvoke(SmtEngine* smtEngine, std::ostream& out) throw()`

  2. src/expr/command.h (line 568)  
     Added function:  
     `Expr getModelCommandInvoke(SmtEngine* smtEngine, std::ostream& out) throw();`

  3. src/main/command_executor.cpp (line 149)  
     Added function:  
     `bool CommandExecutor::doCheckSatCommandSingleton(Command* cmd)`

  4. src/main/command_executor.h (line 81)  
     Added function:
     `bool CommandExecutor::doCheckSatCommandSingleton(Command* cmd);`

  5. src/main/driver_unified.cpp (lines 423 to 456)  
     Added model counting code

  6. src/main/options (line 61)  
     Added command line option `maxsolutions`

  7. src/smt/smt_engine.cpp  
     Commented lines 1057 to 1065 to enable incremental in eager mode

  8. src/theory/bv/options_handlers.h  
     Commented lines 87 to 91 to enable incremental in eager mode

  9. src/theory/bv/theory_bv.cpp  
     Commented line 194 to enable incremental in eager mode


### Files changed in Boolector ###

To be updated ...