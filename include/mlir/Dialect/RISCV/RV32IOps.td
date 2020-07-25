#ifndef MLIR_RISCV_RV32IOPS
#define MLIR_RISCV_RV32IOPS

include "RV32IDialect.td"

def RDAttr     : SignlessIntegerAttrBase<I<5>, "RD register">;
def RS1Attr    : SignlessIntegerAttrBase<I<5>, "RS1 register">;
def RS2Attr    : SignlessIntegerAttrBase<I<5>, "RS2 register">;
def Func3Attr  : SignlessIntegerAttrBase<I<3>, "Function 3-bit">;
def Func7Attr  : SignlessIntegerAttrBase<I<7>, "Function 7-bit">;
def IMM12Attr  : SignlessIntegerAttrBase<I<12>, "Immediate 12-bit (I-type)">;
def SIMM12Attr : SignlessIntegerAttrBase<I<12>, "Immediate 12-bit (S-type)">;
def BIMM12Attr : SignlessIntegerAttrBase<I<12>, "Immediate 12-bit (B-type)">;
def IMM20Attr  : SignlessIntegerAttrBase<I<20>, "Immediate 20-bit (U-type)">;
def JIMM20Attr : SignlessIntegerAttrBase<I<20>, "Immediate 20-bit (J-type)">;
def SHAMT5Attr : SignlessIntegerAttrBase<I<5>, "Shift amount 5-bit">;
def SHAMT6Attr : SignlessIntegerAttrBase<I<6>, "Shift amount 6-bit">;
def FMAttr     : SignlessIntegerAttrBase<I<4>, "Fence mode">;
def PredIAttr  : SignlessIntegerAttrBase<I<1>, "Predecessor set, device input">;
def PredOAttr  : SignlessIntegerAttrBase<I<1>, "Predecessor set, device output">;
def PredRAttr  : SignlessIntegerAttrBase<I<1>, "Predecessor set, device reads">;
def PredWAttr  : SignlessIntegerAttrBase<I<1>, "Predecessor set, device writes">;
def SuccIAttr  : SignlessIntegerAttrBase<I<1>, "Successor set, device input">;
def SuccOAttr  : SignlessIntegerAttrBase<I<1>, "Successor set, device output">;
def SuccRAttr  : SignlessIntegerAttrBase<I<1>, "Successor set, device reads">;
def SuccWAttr  : SignlessIntegerAttrBase<I<1>, "Successor set, device writes">;

def RV32I_LUIOp
    : RV32I_Op<"lui", []>,
      Arguments<(ins RDAttr:$rd, IMM20Attr:$imm20)>;

def RV32I_AUIPCOp
    : RV32I_Op<"auipc", []>,
      Arguments<(ins RDAttr:$rd, IMM20Attr:$imm20)>;

def RV32I_JALOp
    : RV32I_Op<"jal", []>,
      Arguments<(ins RDAttr:$rd, JIMM20Attr:$imm20)>;

def RV32I_JALROp
    : RV32I_Op<"jalr", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_BEQOp
    : RV32I_Op<"beq", []>,
      Arguments<(ins RS1Attr:$rs1, RS2Attr:$rs2, BIMM12Attr:$bimm12)>;

def RV32I_BLTOp
    : RV32I_Op<"blt", []>,
      Arguments<(ins RS1Attr:$rs1, RS2Attr:$rs2, BIMM12Attr:$bimm12)>;

def RV32I_BGEOp
    : RV32I_Op<"bge", []>,
      Arguments<(ins RS1Attr:$rs1, RS2Attr:$rs2, BIMM12Attr:$bimm12)>;

def RV32I_BLTUOp
    : RV32I_Op<"bltu", []>,
      Arguments<(ins RS1Attr:$rs1, RS2Attr:$rs2, BIMM12Attr:$bimm12)>;

def RV32I_BGEUOp
    : RV32I_Op<"bgeu", []>,
      Arguments<(ins RS1Attr:$rs1, RS2Attr:$rs2, BIMM12Attr:$bimm12)>;

def RV32I_LBOp
    : RV32I_Op<"lb", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_LHOp
    : RV32I_Op<"lh", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_LWOp
    : RV32I_Op<"lw", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_LBUOp
    : RV32I_Op<"lbu", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_LHUOp
    : RV32I_Op<"lhu", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_SBOp
    : RV32I_Op<"sb", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, SIMM12Attr:$simm12)>;

def RV32I_SHOp
    : RV32I_Op<"sh", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, SIMM12Attr:$simm12)>;

def RV32I_SWOp
    : RV32I_Op<"sw", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, SIMM12Attr:$simm12)>;

def RV32I_ADDIOp
    : RV32I_Op<"addi", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_SLTIOp
    : RV32I_Op<"slti", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_SLTIUOp
    : RV32I_Op<"sltiu", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_XORIOp
    : RV32I_Op<"xori", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_ORIOp
    : RV32I_Op<"ori", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_ANDIOp
    : RV32I_Op<"andi", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, IMM12Attr:$imm12)>;

def RV32I_SLLI32Op
    : RV32I_Op<"slli", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, SHAMT5Attr:$shamt5)>;

def RV32I_SRLI32Op
    : RV32I_Op<"srli", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, SHAMT5Attr:$shamt5)>;

def RV32I_SRAI32Op
    : RV32I_Op<"srai", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, SHAMT5Attr:$shamt5)>;

def RV32I_ADDOp
    : RV32I_Op<"add", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_SUBOp
    : RV32I_Op<"sub", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_SLLOp
    : RV32I_Op<"sll", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_SLTOp
    : RV32I_Op<"slt", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_SLTUOp
    : RV32I_Op<"sltu", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_XOROp
    : RV32I_Op<"xor", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_SRLOp
    : RV32I_Op<"srl", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_SRAOp
    : RV32I_Op<"sra", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_OROp
    : RV32I_Op<"or", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_ANDOp
    : RV32I_Op<"and", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, RS2Attr:$rs2)>;

def RV32I_FENCEOp
    : RV32I_Op<"fence", []>,
      Arguments<(ins RDAttr:$rd, RS1Attr:$rs1, FMAttr:$fm, PredIAttr:$pi,
                     PredOAttr:$po, PredRAttr:$pr, PredWAttr:$pw,
                     SuccIAttr:$si, SuccOAttr:$so, SuccRAttr:$sr,
                     SuccWAttr:$sw)>;

def RV32I_ECALLOp : RV32I_Op<"ecall", []>;

def RV32I_EBREAKOp : RV32I_Op<"ebreak", []>;

#endif // MLIR_RISCV_RV32IOPS
