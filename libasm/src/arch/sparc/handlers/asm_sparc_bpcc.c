#include "libasm.h"

int
asm_sparc_bpcc(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_pbranch opcodep;
  struct s_asm_proc_sparc *inter;
  sparc_convert_pbranch(&opcodep, buf, proc);

  inter = proc->internals;

  ins->instr = inter->bcc_table[opcodep.cond];
  ins->type = ASM_TYPE_CONDBRANCH;
  ins->nb_op = 2;
  ins->op1.type = ASM_SP_OTYPE_DISPLACEMENT;
  ins->op1.imm = opcodep.imm;
  ins->op2.type = ASM_SP_OTYPE_CC;
  ins->op2.base_reg = opcodep.cc + 4;
  ins->annul = opcodep.a;
  ins->prediction = opcodep.p;

  /* Synthetics */
  if (ins->instr == ASM_SP_BN &&
      ins->annul && ins->prediction && ins->op2.base_reg == ASM_SP_XCC) {

    ins->instr = ASM_SP_IPREFETCH;
    ins->nb_op = 1;
    ins->type = ASM_TYPE_NONE;
  }

  return 4;
}
