// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"



// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, Vtop* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_dumping(false)
    , __Vm_dumperp(nullptr)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_top__module1_v1_0_S00_AXI_inst__u_avail_cnt__gen_blk_0__counter.configure(this, name(), "top.module1_v1_0_S00_AXI_inst.u_avail_cnt.gen_blk_0.counter", "counter", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__module1_v1_0_S00_AXI_inst__u_fifo1__unhardened__un__fifo.configure(this, name(), "top.module1_v1_0_S00_AXI_inst.u_fifo1.unhardened.un.fifo", "fifo", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__module1_v1_0_S00_AXI_inst__u_fifo2__unhardened__un__fifo.configure(this, name(), "top.module1_v1_0_S00_AXI_inst.u_fifo2.unhardened.un.fifo", "fifo", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__module1_v1_0_S00_AXI_inst__u_free_cnt__gen_blk_0__counter.configure(this, name(), "top.module1_v1_0_S00_AXI_inst.u_free_cnt.gen_blk_0.counter", "counter", -9, VerilatedScope::SCOPE_OTHER);
}
