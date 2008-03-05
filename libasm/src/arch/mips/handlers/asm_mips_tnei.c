/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_tnei(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_TNEI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Trap */

   return 777;
}
