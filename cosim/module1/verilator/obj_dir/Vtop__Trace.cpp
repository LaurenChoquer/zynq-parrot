// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i));
            tracep->chgBit(oldp+1,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
            tracep->chgBit(oldp+2,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
            tracep->chgIData(oldp+3,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i),32);
            tracep->chgIData(oldp+4,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_i),32);
            tracep->chgBit(oldp+5,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)))));
            tracep->chgBit(oldp+6,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)))));
            tracep->chgIData(oldp+7,(((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r))
                                       ? vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                                      [vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r]
                                       : 0U)),32);
            tracep->chgIData(oldp+8,(((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r))
                                       ? vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                                      [vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r]
                                       : 0U)),32);
            tracep->chgBit(oldp+9,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i));
            tracep->chgCData(oldp+10,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt),3);
            tracep->chgCData(oldp+11,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt),3);
            tracep->chgCData(oldp+12,((0xffU & vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16)),8);
            tracep->chgCData(oldp+13,((0xffU & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                                >> 0x10U))),8);
            tracep->chgCData(oldp+14,((((0xffU & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                                  >> 0x10U)) 
                                        >= (0xffU & vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16))
                                        ? 0U : (0xffU 
                                                & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                                   - 
                                                   (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                                    >> 0x10U))))),8);
            tracep->chgCData(oldp+15,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt),8);
            tracep->chgCData(oldp+16,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr),6);
            tracep->chgBit(oldp+17,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready));
            tracep->chgBit(oldp+18,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready));
            tracep->chgCData(oldp+19,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bresp),2);
            tracep->chgBit(oldp+20,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid));
            tracep->chgCData(oldp+21,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr),6);
            tracep->chgBit(oldp+22,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready));
            tracep->chgIData(oldp+23,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rdata),32);
            tracep->chgCData(oldp+24,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rresp),2);
            tracep->chgBit(oldp+25,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid));
            tracep->chgIData(oldp+26,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16),32);
            tracep->chgBit(oldp+27,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en));
            tracep->chgCData(oldp+28,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r),3);
            tracep->chgCData(oldp+29,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r),3);
            tracep->chgBit(oldp+30,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full));
            tracep->chgBit(oldp+31,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty));
            tracep->chgCData(oldp+32,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap))
                                              ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                                 + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i))
                                              : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap)))),3);
            tracep->chgBit(oldp+33,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
            tracep->chgBit(oldp+34,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
            tracep->chgBit(oldp+35,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs));
            tracep->chgCData(oldp+36,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                             + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)))),3);
            tracep->chgCData(oldp+37,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap),4);
            tracep->chgIData(oldp+38,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[0]),32);
            tracep->chgIData(oldp+39,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[1]),32);
            tracep->chgIData(oldp+40,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[2]),32);
            tracep->chgIData(oldp+41,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[3]),32);
            tracep->chgIData(oldp+42,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[4]),32);
            tracep->chgBit(oldp+43,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque));
            tracep->chgCData(oldp+44,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r),3);
            tracep->chgCData(oldp+45,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r),3);
            tracep->chgBit(oldp+46,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full));
            tracep->chgBit(oldp+47,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty));
            tracep->chgBit(oldp+48,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
            tracep->chgBit(oldp+49,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
            tracep->chgBit(oldp+50,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs));
            tracep->chgCData(oldp+51,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap))
                                              ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                                 + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque))
                                              : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap)))),3);
            tracep->chgCData(oldp+52,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                             + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)))),3);
            tracep->chgCData(oldp+53,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap),4);
            tracep->chgIData(oldp+54,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[0]),32);
            tracep->chgIData(oldp+55,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[1]),32);
            tracep->chgIData(oldp+56,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[2]),32);
            tracep->chgIData(oldp+57,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[3]),32);
            tracep->chgIData(oldp+58,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[4]),32);
            tracep->chgBit(oldp+59,(((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i) 
                                     & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+60,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod),32);
            tracep->chgBit(oldp+61,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg_wren));
            tracep->chgBit(oldp+62,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque));
            tracep->chgCData(oldp+63,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap),4);
            tracep->chgCData(oldp+64,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap),4);
        }
        tracep->chgBit(oldp+65,(vlTOPp->s00_axi_aclk));
        tracep->chgBit(oldp+66,(vlTOPp->s00_axi_aresetn));
        tracep->chgCData(oldp+67,(vlTOPp->s00_axi_awaddr),6);
        tracep->chgCData(oldp+68,(vlTOPp->s00_axi_awprot),3);
        tracep->chgBit(oldp+69,(vlTOPp->s00_axi_awvalid));
        tracep->chgBit(oldp+70,(vlTOPp->s00_axi_awready));
        tracep->chgIData(oldp+71,(vlTOPp->s00_axi_wdata),32);
        tracep->chgCData(oldp+72,(vlTOPp->s00_axi_wstrb),4);
        tracep->chgBit(oldp+73,(vlTOPp->s00_axi_wvalid));
        tracep->chgBit(oldp+74,(vlTOPp->s00_axi_wready));
        tracep->chgCData(oldp+75,(vlTOPp->s00_axi_bresp),2);
        tracep->chgBit(oldp+76,(vlTOPp->s00_axi_bvalid));
        tracep->chgBit(oldp+77,(vlTOPp->s00_axi_bready));
        tracep->chgCData(oldp+78,(vlTOPp->s00_axi_araddr),6);
        tracep->chgCData(oldp+79,(vlTOPp->s00_axi_arprot),3);
        tracep->chgBit(oldp+80,(vlTOPp->s00_axi_arvalid));
        tracep->chgBit(oldp+81,(vlTOPp->s00_axi_arready));
        tracep->chgIData(oldp+82,(vlTOPp->s00_axi_rdata),32);
        tracep->chgCData(oldp+83,(vlTOPp->s00_axi_rresp),2);
        tracep->chgBit(oldp+84,(vlTOPp->s00_axi_rvalid));
        tracep->chgBit(oldp+85,(vlTOPp->s00_axi_rready));
        tracep->chgBit(oldp+86,((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready) 
                                  & (IData)(vlTOPp->s00_axi_arvalid)) 
                                 & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid)))));
        tracep->chgIData(oldp+87,(((0x20U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                    ? 0U : ((0x10U 
                                             & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                             ? ((8U 
                                                 & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                 ? 0U
                                                 : 
                                                ((4U 
                                                  & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                    ? 0U
                                                    : vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16))))
                                             : ((8U 
                                                 & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                 ? 
                                                ((4U 
                                                  & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                    ? 0U
                                                    : vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                    ? 0U
                                                    : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt))))
                                                 : 
                                                ((4U 
                                                  & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                  ? 0U
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                    ? 0U
                                                    : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt)))))))),32);
        tracep->chgBit(oldp+88,((1U & (~ (IData)(vlTOPp->s00_axi_aresetn)))));
        tracep->chgCData(oldp+89,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap))
                                          ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                             + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque))
                                          : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap)))),3);
        tracep->chgCData(oldp+90,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                         + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)))),3);
        tracep->chgBit(oldp+91,(((IData)(vlTOPp->s00_axi_wvalid) 
                                 & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
        tracep->chgCData(oldp+92,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap))
                                          ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                             + (IData)(vlTOPp->s00_axi_rready))
                                          : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap)))),3);
        tracep->chgCData(oldp+93,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                         + (IData)(vlTOPp->s00_axi_rready)))),3);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedFst* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
