// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VerilatedContext* Vtop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 4, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
            } else {
                __Vchange = _change_request(vlSymsp);
            }
        } while (VL_UNLIKELY(__Vchange));
    }
    
    void Vtop::eval_end_step() {
        VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vtop::eval_end_step\n"); );
#ifdef VM_TRACE
        Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
        Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
        // Tracing
        if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) _traceDump();
#endif  // VM_TRACE
    }
    
    void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
        vlSymsp->__Vm_didInit = true;
        _eval_initial(vlSymsp);
        vlSymsp->__Vm_activity = true;
        // Evaluate till stable
        int __VclockLoop = 0;
        QData __Vchange = 1;
        do {
            _eval_settle(vlSymsp);
            _eval(vlSymsp);
            if (VL_UNLIKELY(++__VclockLoop > 100)) {
                // About to fail, so enable debug to see what's not settling.
                // Note you must run make with OPT=-DVL_DEBUG for debug prints.
                int __Vsaved_debug = Verilated::debug();
                Verilated::debug(1);
                __Vchange = _change_request(vlSymsp);
                Verilated::debug(__Vsaved_debug);
                VL_FATAL_MT("top.v", 4, "",
                    "Verilated model didn't DC converge\n"
                    "- See https://verilator.org/warn/DIDNOTCONVERGE");
                } else {
                    __Vchange = _change_request(vlSymsp);
                }
            } while (VL_UNLIKELY(__Vchange));
        }
        
        VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
            Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Variables
            CData/*0:0*/ __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready;
            CData/*0:0*/ __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en;
            CData/*0:0*/ __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready;
            CData/*0:0*/ __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid;
            CData/*0:0*/ __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid;
            CData/*2:0*/ __Vdlyvdim0__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            CData/*0:0*/ __Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            CData/*2:0*/ __Vdlyvdim0__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            CData/*0:0*/ __Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            IData/*31:0*/ __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16;
            IData/*31:0*/ __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i;
            IData/*31:0*/ __Vdlyvval__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            IData/*31:0*/ __Vdlyvval__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            // Body
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid;
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready;
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en;
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid;
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready;
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i;
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16;
            __Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 = 0U;
            __Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 = 0U;
            if (vlTOPp->s00_axi_aresetn) {
                if ((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready) 
                      & (IData)(vlTOPp->s00_axi_arvalid)) 
                     & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid)))) {
                    __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid = 1U;
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rresp = 0U;
                } else {
                    if (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid) 
                         & (IData)(vlTOPp->s00_axi_rready))) {
                        __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid = 0U;
                    }
                }
            } else {
                __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid = 0U;
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rresp = 0U;
            }
            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready 
                = ((IData)(vlTOPp->s00_axi_aresetn) 
                   & ((((~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready)) 
                        & (IData)(vlTOPp->s00_axi_wvalid)) 
                       & (IData)(vlTOPp->s00_axi_awvalid)) 
                      & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en)));
            if (vlTOPp->s00_axi_aresetn) {
                if ((((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready) 
                        & (IData)(vlTOPp->s00_axi_awvalid)) 
                       & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid))) 
                      & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready)) 
                     & (IData)(vlTOPp->s00_axi_wvalid))) {
                    __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid = 1U;
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bresp = 0U;
                } else {
                    if (((IData)(vlTOPp->s00_axi_bready) 
                         & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid))) {
                        __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid = 0U;
                    }
                }
            } else {
                __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid = 0U;
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bresp = 0U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if (((((~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready)) 
                       & (IData)(vlTOPp->s00_axi_awvalid)) 
                      & (IData)(vlTOPp->s00_axi_wvalid)) 
                     & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en))) {
                    __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready = 1U;
                    __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en = 0U;
                } else {
                    if (((IData)(vlTOPp->s00_axi_bready) 
                         & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid))) {
                        __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en = 1U;
                        __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready = 0U;
                    } else {
                        __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready = 0U;
                    }
                }
            } else {
                __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready = 0U;
                __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en = 1U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg_wren) {
                    if ((4U == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr))) {
                        __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i 
                            = vlTOPp->s00_axi_wdata;
                    } else {
                        if ((0x10U != (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr))) {
                            __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i 
                                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i;
                        }
                    }
                }
            } else {
                __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i = 0U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg_wren) {
                    if ((4U != (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr))) {
                        __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                            = ((0x10U == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr))
                                ? vlTOPp->s00_axi_wdata
                                : vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16);
                    }
                }
            } else {
                __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 = 0U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque) 
                     | (IData)(vlTOPp->s00_axi_rready))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r 
                        = vlTOPp->s00_axi_rready;
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r = 1U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if ((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready) 
                      & (IData)(vlTOPp->s00_axi_arvalid)) 
                     & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid)))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rdata 
                        = ((0x20U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                            ? 0U : ((0x10U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                     ? ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                         ? 0U : ((4U 
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
                                     : ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                         ? ((4U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                             ? ((2U 
                                                 & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                  ? 0U
                                                  : vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod))
                                             : ((2U 
                                                 & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                                  ? 0U
                                                  : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt))))
                                         : ((4U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                             ? 0U : 
                                            ((2U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                              ? 0U : 
                                             ((1U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
                                               ? 0U
                                               : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt)))))));
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rdata = 0U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque) 
                     | (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r 
                        = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i;
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r = 1U;
            }
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt 
                = ((IData)(vlTOPp->s00_axi_aresetn)
                    ? (7U & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt) 
                              - ((IData)(vlTOPp->s00_axi_wvalid) 
                                 & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))) 
                             + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)))
                    : 5U);
            if (vlTOPp->s00_axi_aresetn) {
                if (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque) 
                     | (IData)(vlTOPp->s00_axi_rready))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r 
                        = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque;
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r = 0U;
            }
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt 
                = ((IData)(vlTOPp->s00_axi_aresetn)
                    ? (7U & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt) 
                              - (IData)(vlTOPp->s00_axi_rready)) 
                             + ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i) 
                                & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))))
                    : 0U);
            if (vlTOPp->s00_axi_aresetn) {
                if (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque) 
                     | (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r 
                        = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque;
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r = 0U;
            }
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r 
                = ((IData)(vlTOPp->s00_axi_aresetn)
                    ? (7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap))
                              ? (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap)
                              : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap)))
                    : 0U);
            if (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque) {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT____Vlvbound1 
                    = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i;
                if ((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r))) {
                    __Vdlyvval__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 
                        = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT____Vlvbound1;
                    __Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 = 1U;
                    __Vdlyvdim0__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 
                        = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r;
                }
            }
            if (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque) {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT____Vlvbound1 
                    = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_i;
                if ((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r))) {
                    __Vdlyvval__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 
                        = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT____Vlvbound1;
                    __Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 = 1U;
                    __Vdlyvdim0__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0 
                        = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r;
                }
            }
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready 
                = __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready;
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid 
                = __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid;
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid 
                = __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid;
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i 
                = __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i;
            if (__Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0) {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                            [__Vdlyvdim0__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0] 
                    = __Vdlyvval__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            }
            vlTOPp->s00_axi_rresp = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rresp;
            vlTOPp->s00_axi_bresp = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bresp;
            vlTOPp->s00_axi_bvalid = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid;
            if (vlTOPp->s00_axi_aresetn) {
                if (((((~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready)) 
                       & (IData)(vlTOPp->s00_axi_awvalid)) 
                      & (IData)(vlTOPp->s00_axi_wvalid)) 
                     & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr 
                        = vlTOPp->s00_axi_awaddr;
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr = 0U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if (((~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready)) 
                     & (IData)(vlTOPp->s00_axi_arvalid))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready = 1U;
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr 
                        = vlTOPp->s00_axi_araddr;
                } else {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready = 0U;
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready = 0U;
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr = 0U;
            }
            if (vlTOPp->s00_axi_aresetn) {
                if (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty) {
                    if ((0U == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt))) {
                        vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i = 0U;
                        vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i = 1U;
                    } else {
                        vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt 
                            = (0xffU & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt) 
                                        - (IData)(1U)));
                        vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i = 0U;
                    }
                } else {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt 
                        = (((0xffU & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                      >> 0x10U)) >= 
                            (0xffU & vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16))
                            ? 0U : (0xffU & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                             - (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                                >> 0x10U))));
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i = 1U;
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i = 0U;
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt = 0U;
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i = 0U;
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i = 0U;
            }
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r 
                = ((IData)(vlTOPp->s00_axi_aresetn)
                    ? (7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap))
                              ? (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap)
                              : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap)))
                    : 0U);
            vlTOPp->s00_axi_rdata = ((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r))
                                      ? vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                                     [vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r]
                                      : 0U);
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r 
                = ((IData)(vlTOPp->s00_axi_aresetn)
                    ? (7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap))
                              ? (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap)
                              : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap)))
                    : 0U);
            if (vlTOPp->s00_axi_aresetn) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)))) {
                    vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_i 
                        = ((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r))
                            ? vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                           [vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r]
                            : 0U);
                }
            } else {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_i = 0U;
            }
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en 
                = __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en;
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready 
                = __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready;
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                = __Vdly__top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16;
            if (__Vdlyvset__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0) {
                vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                            [__Vdlyvdim0__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0] 
                    = __Vdlyvval__top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem__v0;
            }
            vlTOPp->s00_axi_awready = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready;
            vlTOPp->s00_axi_arready = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready;
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                   == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r 
                = ((IData)(vlTOPp->s00_axi_aresetn)
                    ? (7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap))
                              ? (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap)
                              : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap)))
                    : 0U);
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
            vlTOPp->s00_axi_rvalid = (1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i) 
                   & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap 
                = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                            - (IData)(5U)) + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap 
                = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                         + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                   == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap 
                = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                            - (IData)(5U)) + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap 
                = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                         + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs) 
                   & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
            vlTOPp->s00_axi_wready = (1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)));
        }
        
        VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
            Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            if (VL_UNLIKELY((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty) 
                              & (IData)(vlTOPp->s00_axi_rready)) 
                             & (IData)(vlTOPp->s00_axi_aresetn)))) {
                VL_WRITEF("%Ntop.module1_v1_0_S00_AXI_inst.u_fifo2.unhardened.un.fifo error: deque empty fifo at time %t\n",
                          vlSymsp->name(),64,(0x3e8ULL 
                                              * (QData)(VL_TIME_UNITED_Q(1000))));
            }
            if (VL_UNLIKELY((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty) 
                              & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)) 
                             & (IData)(vlTOPp->s00_axi_aresetn)))) {
                VL_WRITEF("%Ntop.module1_v1_0_S00_AXI_inst.u_fifo1.unhardened.un.fifo error: deque empty fifo at time %t\n",
                          vlSymsp->name(),64,(0x3e8ULL 
                                              * (QData)(VL_TIME_UNITED_Q(1000))));
            }
            if (VL_UNLIKELY((((5U == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt)) 
                              & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)) 
                             & (IData)(vlTOPp->s00_axi_aresetn)))) {
                VL_WRITEF("%Ntop.module1_v1_0_S00_AXI_inst.u_free_cnt.gen_blk_0.counter error: counter overflow at time %t\n",
                          vlSymsp->name(),64,(0x3e8ULL 
                                              * (QData)(VL_TIME_UNITED_Q(1000))));
            }
            if (VL_UNLIKELY((((0U == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt)) 
                              & ((IData)(vlTOPp->s00_axi_wvalid) 
                                 & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))) 
                             & (IData)(vlTOPp->s00_axi_aresetn)))) {
                VL_WRITEF("%Ntop.module1_v1_0_S00_AXI_inst.u_free_cnt.gen_blk_0.counter error: counter underflow at time %t\n",
                          vlSymsp->name(),64,(0x3e8ULL 
                                              * (QData)(VL_TIME_UNITED_Q(1000))));
            }
            if (VL_UNLIKELY((((5U == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt)) 
                              & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i) 
                                 & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))) 
                             & (IData)(vlTOPp->s00_axi_aresetn)))) {
                VL_WRITEF("%Ntop.module1_v1_0_S00_AXI_inst.u_avail_cnt.gen_blk_0.counter error: counter overflow at time %t\n",
                          vlSymsp->name(),64,(0x3e8ULL 
                                              * (QData)(VL_TIME_UNITED_Q(1000))));
            }
            if (VL_UNLIKELY((((0U == (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt)) 
                              & (IData)(vlTOPp->s00_axi_rready)) 
                             & (IData)(vlTOPp->s00_axi_aresetn)))) {
                VL_WRITEF("%Ntop.module1_v1_0_S00_AXI_inst.u_avail_cnt.gen_blk_0.counter error: counter underflow at time %t\n",
                          vlSymsp->name(),64,(0x3e8ULL 
                                              * (QData)(VL_TIME_UNITED_Q(1000))));
            }
        }
        
        VL_INLINE_OPT void Vtop::_combo__TOP__5(Vtop__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__5\n"); );
            Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap 
                = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                            - (IData)(5U)) + (IData)(vlTOPp->s00_axi_rready)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_nowrap 
                = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                         + (IData)(vlTOPp->s00_axi_rready)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg_wren 
                = ((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready) 
                     & (IData)(vlTOPp->s00_axi_wvalid)) 
                    & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready)) 
                   & (IData)(vlTOPp->s00_axi_awvalid));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod 
                = ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)
                    ? 0xffffffffU : vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod);
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque 
                = ((IData)(vlTOPp->s00_axi_wvalid) 
                   & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap 
                = (0xfU & (((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                            - (IData)(5U)) + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
            vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_nowrap 
                = (7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                         + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)));
        }
        
        void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
            Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            if (((IData)(vlTOPp->s00_axi_aclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__s00_axi_aclk)))) {
                vlTOPp->_sequent__TOP__2(vlSymsp);
                vlTOPp->__Vm_traceActivity[1U] = 1U;
            }
            if (((~ (IData)(vlTOPp->s00_axi_aclk)) 
                 & (IData)(vlTOPp->__Vclklast__TOP__s00_axi_aclk))) {
                vlTOPp->_sequent__TOP__3(vlSymsp);
            }
            vlTOPp->_combo__TOP__5(vlSymsp);
            vlTOPp->__Vm_traceActivity[2U] = 1U;
            // Final
            vlTOPp->__Vclklast__TOP__s00_axi_aclk = vlTOPp->s00_axi_aclk;
        }
        
        VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
            Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            return (vlTOPp->_change_request_1(vlSymsp));
        }
        
        VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
            Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            // Change detection
            QData __req = false;  // Logically a bool
            __req |= ((vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod ^ vlTOPp->__Vchglast__TOP__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod));
            VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod ^ vlTOPp->__Vchglast__TOP__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod))) VL_DBG_MSGF("        CHANGE: axi_periph_v1_0_S00_AXI.v:101: top.module1_v1_0_S00_AXI_inst.f2_data_o_mod\n"); );
            // Final
            vlTOPp->__Vchglast__TOP__top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod 
                = vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod;
            return __req;
        }
        
#ifdef VL_DEBUG
        void Vtop::_eval_debug_assertions() {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
            // Body
            if (VL_UNLIKELY((s00_axi_aclk & 0xfeU))) {
                Verilated::overWidthError("s00_axi_aclk");}
            if (VL_UNLIKELY((s00_axi_aresetn & 0xfeU))) {
                Verilated::overWidthError("s00_axi_aresetn");}
            if (VL_UNLIKELY((s00_axi_awaddr & 0xc0U))) {
                Verilated::overWidthError("s00_axi_awaddr");}
            if (VL_UNLIKELY((s00_axi_awprot & 0xf8U))) {
                Verilated::overWidthError("s00_axi_awprot");}
            if (VL_UNLIKELY((s00_axi_awvalid & 0xfeU))) {
                Verilated::overWidthError("s00_axi_awvalid");}
            if (VL_UNLIKELY((s00_axi_wstrb & 0xf0U))) {
                Verilated::overWidthError("s00_axi_wstrb");}
            if (VL_UNLIKELY((s00_axi_wvalid & 0xfeU))) {
                Verilated::overWidthError("s00_axi_wvalid");}
            if (VL_UNLIKELY((s00_axi_bready & 0xfeU))) {
                Verilated::overWidthError("s00_axi_bready");}
            if (VL_UNLIKELY((s00_axi_araddr & 0xc0U))) {
                Verilated::overWidthError("s00_axi_araddr");}
            if (VL_UNLIKELY((s00_axi_arprot & 0xf8U))) {
                Verilated::overWidthError("s00_axi_arprot");}
            if (VL_UNLIKELY((s00_axi_arvalid & 0xfeU))) {
                Verilated::overWidthError("s00_axi_arvalid");}
            if (VL_UNLIKELY((s00_axi_rready & 0xfeU))) {
                Verilated::overWidthError("s00_axi_rready");}
        }
#endif  // VL_DEBUG
