// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(_vcontextp__, this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vtop::~Vtop() {
#ifdef VM_TRACE
    if (VL_UNLIKELY(__VlSymsp->__Vm_dumping)) _traceDumpClose();
#endif  // VM_TRACE
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<3>/*95:0*/ __Vtemp1;
    // Body
    if (VL_UNLIKELY((0U != VL_TESTPLUSARGS_I("bsg_trace")))) {
        __Vtemp1[0U] = 0x2e667374U;
        __Vtemp1[1U] = 0x72616365U;
        __Vtemp1[2U] = 0x74U;
        vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp1));
        vlSymsp->TOPp->_traceDumpOpen();
        VL_WRITEF("[%0t] Tracing to trace.fst...\n\n",
                  64,(0x3e8ULL * (QData)(VL_TIME_UNITED_Q(1000))));
    }
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->s00_axi_bresp = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bresp;
    vlTOPp->s00_axi_bvalid = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid;
    vlTOPp->s00_axi_rresp = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rresp;
    vlTOPp->s00_axi_rdata = ((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r))
                              ? vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                             [vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r]
                              : 0U);
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap 
        = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                    - (IData)(5U)) + (IData)(vlTOPp->s00_axi_rready)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap 
        = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                 + (IData)(vlTOPp->s00_axi_rready)));
    vlTOPp->s00_axi_awready = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready;
    vlTOPp->s00_axi_arready = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready;
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg_wren 
        = ((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready) 
             & (IData)(vlTOPp->s00_axi_wvalid)) & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready)) 
           & (IData)(vlTOPp->s00_axi_awvalid));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
           == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap 
        = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                    - (IData)(5U)) + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap 
        = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                 + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
           == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
           & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
           & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
           & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
           & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)
            ? 0xffffffffU : vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod);
    vlTOPp->s00_axi_rvalid = (1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque 
        = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i) 
           & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)));
    vlTOPp->s00_axi_wready = (1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque 
        = ((IData)(vlTOPp->s00_axi_wvalid) & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap 
        = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                    - (IData)(5U)) + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap 
        = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                 + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap 
        = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                    - (IData)(5U)) + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap 
        = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                 + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__s00_axi_aclk = vlTOPp->s00_axi_aclk;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    s00_axi_aclk = VL_RAND_RESET_I(1);
    s00_axi_aresetn = VL_RAND_RESET_I(1);
    s00_axi_awaddr = VL_RAND_RESET_I(6);
    s00_axi_awprot = VL_RAND_RESET_I(3);
    s00_axi_awvalid = VL_RAND_RESET_I(1);
    s00_axi_awready = VL_RAND_RESET_I(1);
    s00_axi_wdata = VL_RAND_RESET_I(32);
    s00_axi_wstrb = VL_RAND_RESET_I(4);
    s00_axi_wvalid = VL_RAND_RESET_I(1);
    s00_axi_wready = VL_RAND_RESET_I(1);
    s00_axi_bresp = VL_RAND_RESET_I(2);
    s00_axi_bvalid = VL_RAND_RESET_I(1);
    s00_axi_bready = VL_RAND_RESET_I(1);
    s00_axi_araddr = VL_RAND_RESET_I(6);
    s00_axi_arprot = VL_RAND_RESET_I(3);
    s00_axi_arvalid = VL_RAND_RESET_I(1);
    s00_axi_arready = VL_RAND_RESET_I(1);
    s00_axi_rdata = VL_RAND_RESET_I(32);
    s00_axi_rresp = VL_RAND_RESET_I(2);
    s00_axi_rvalid = VL_RAND_RESET_I(1);
    s00_axi_rready = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i = VL_RAND_RESET_I(32);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_i = VL_RAND_RESET_I(32);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt = VL_RAND_RESET_I(8);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod = VL_RAND_RESET_I(32);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr = VL_RAND_RESET_I(6);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bresp = VL_RAND_RESET_I(2);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr = VL_RAND_RESET_I(6);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rdata = VL_RAND_RESET_I(32);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rresp = VL_RAND_RESET_I(2);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 = VL_RAND_RESET_I(32);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg_wren = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__byte_index = VL_RAND_RESET_I(32);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap = VL_RAND_RESET_I(4);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<5; ++__Vi0) {
        top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs = VL_RAND_RESET_I(1);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap = VL_RAND_RESET_I(4);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap = VL_RAND_RESET_I(3);
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<5; ++__Vi0) {
        top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    __Vchglast__TOP__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
