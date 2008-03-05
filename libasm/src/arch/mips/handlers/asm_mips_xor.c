/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* XOR rd,rs,rt */

int asm_mips_xor(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_XOR;
   ins->type = ASM_TYPE_ARITH;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 777;
}
