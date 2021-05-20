// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::_traceDump() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumperp->dump(VL_TIME_Q());
}
void Vtop::_traceDumpOpen() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    if (VL_UNLIKELY(!__VlSymsp->__Vm_dumperp)) {
        __VlSymsp->__Vm_dumperp = new VerilatedFstC();
        trace(__VlSymsp->__Vm_dumperp, 0, 0);
        std::string dumpfile = __VlSymsp->_vm_contextp__->dumpfileCheck();
        __VlSymsp->__Vm_dumperp->open(dumpfile.c_str());
        __VlSymsp->__Vm_dumping = true;
    }
}
void Vtop::_traceDumpClose() {
    const VerilatedLockGuard lock(__VlSymsp->__Vm_dumperMutex);
    __VlSymsp->__Vm_dumping = false;
    VL_DO_CLEAR(delete __VlSymsp->__Vm_dumperp, __VlSymsp->__Vm_dumperp = nullptr);
}
void Vtop::trace(VerilatedFstC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+66,"s00_axi_aclk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+67,"s00_axi_aresetn",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+68,"s00_axi_awaddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
        tracep->declBus(c+69,"s00_axi_awprot",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+70,"s00_axi_awvalid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+71,"s00_axi_awready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+72,"s00_axi_wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+73,"s00_axi_wstrb",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBit(c+74,"s00_axi_wvalid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+75,"s00_axi_wready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+76,"s00_axi_bresp",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
        tracep->declBit(c+77,"s00_axi_bvalid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+78,"s00_axi_bready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+79,"s00_axi_araddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
        tracep->declBus(c+80,"s00_axi_arprot",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+81,"s00_axi_arvalid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+82,"s00_axi_arready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+83,"s00_axi_rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+84,"s00_axi_rresp",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
        tracep->declBit(c+85,"s00_axi_rvalid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+86,"s00_axi_rready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+95,"top C_S00_AXI_DATA_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+96,"top C_S00_AXI_ADDR_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top s00_axi_aclk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+67,"top s00_axi_aresetn",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+68,"top s00_axi_awaddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
        tracep->declBus(c+69,"top s00_axi_awprot",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+70,"top s00_axi_awvalid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+71,"top s00_axi_awready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+72,"top s00_axi_wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+73,"top s00_axi_wstrb",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBit(c+74,"top s00_axi_wvalid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+75,"top s00_axi_wready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+76,"top s00_axi_bresp",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
        tracep->declBit(c+77,"top s00_axi_bvalid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+78,"top s00_axi_bready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+79,"top s00_axi_araddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
        tracep->declBus(c+80,"top s00_axi_arprot",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+81,"top s00_axi_arvalid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+82,"top s00_axi_arready",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+83,"top s00_axi_rdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+84,"top s00_axi_rresp",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
        tracep->declBit(c+85,"top s00_axi_rvalid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+86,"top s00_axi_rready",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+95,"top module1_v1_0_S00_AXI_inst C_S_AXI_DATA_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+96,"top module1_v1_0_S00_AXI_inst C_S_AXI_ADDR_WIDTH",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst S_AXI_ACLK",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+67,"top module1_v1_0_S00_AXI_inst S_AXI_ARESETN",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+68,"top module1_v1_0_S00_AXI_inst S_AXI_AWADDR",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
        tracep->declBus(c+69,"top module1_v1_0_S00_AXI_inst S_AXI_AWPROT",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+70,"top module1_v1_0_S00_AXI_inst S_AXI_AWVALID",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+71,"top module1_v1_0_S00_AXI_inst S_AXI_AWREADY",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+72,"top module1_v1_0_S00_AXI_inst S_AXI_WDATA",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+73,"top module1_v1_0_S00_AXI_inst S_AXI_WSTRB",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBit(c+74,"top module1_v1_0_S00_AXI_inst S_AXI_WVALID",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+75,"top module1_v1_0_S00_AXI_inst S_AXI_WREADY",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+76,"top module1_v1_0_S00_AXI_inst S_AXI_BRESP",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
        tracep->declBit(c+77,"top module1_v1_0_S00_AXI_inst S_AXI_BVALID",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+78,"top module1_v1_0_S00_AXI_inst S_AXI_BREADY",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+79,"top module1_v1_0_S00_AXI_inst S_AXI_ARADDR",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
        tracep->declBus(c+80,"top module1_v1_0_S00_AXI_inst S_AXI_ARPROT",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+81,"top module1_v1_0_S00_AXI_inst S_AXI_ARVALID",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+82,"top module1_v1_0_S00_AXI_inst S_AXI_ARREADY",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+83,"top module1_v1_0_S00_AXI_inst S_AXI_RDATA",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+84,"top module1_v1_0_S00_AXI_inst S_AXI_RRESP",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
        tracep->declBit(c+85,"top module1_v1_0_S00_AXI_inst S_AXI_RVALID",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+86,"top module1_v1_0_S00_AXI_inst S_AXI_RREADY",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+74,"top module1_v1_0_S00_AXI_inst f1_v_i",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+1,"top module1_v1_0_S00_AXI_inst f2_v_i",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+2,"top module1_v1_0_S00_AXI_inst f1_ready_o",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+3,"top module1_v1_0_S00_AXI_inst f2_ready_o",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+4,"top module1_v1_0_S00_AXI_inst f1_data_i",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBus(c+5,"top module1_v1_0_S00_AXI_inst f2_data_i",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBit(c+6,"top module1_v1_0_S00_AXI_inst f1_v_o",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+7,"top module1_v1_0_S00_AXI_inst f2_v_o",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+8,"top module1_v1_0_S00_AXI_inst f1_data_o",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBus(c+9,"top module1_v1_0_S00_AXI_inst f2_data_o",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBit(c+10,"top module1_v1_0_S00_AXI_inst f1_yumi_i",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+86,"top module1_v1_0_S00_AXI_inst f2_yumi_i",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+11,"top module1_v1_0_S00_AXI_inst free_cnt",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+12,"top module1_v1_0_S00_AXI_inst avail_cnt",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+13,"top module1_v1_0_S00_AXI_inst rep",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 7,0);
        tracep->declBus(c+14,"top module1_v1_0_S00_AXI_inst drop",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 7,0);
        tracep->declBus(c+15,"top module1_v1_0_S00_AXI_inst rep_factor",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 7,0);
        tracep->declBus(c+16,"top module1_v1_0_S00_AXI_inst cnt",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 7,0);
        tracep->declBus(c+61,"top module1_v1_0_S00_AXI_inst f2_data_o_mod",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBus(c+17,"top module1_v1_0_S00_AXI_inst axi_awaddr",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 5,0);
        tracep->declBit(c+18,"top module1_v1_0_S00_AXI_inst axi_awready",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+19,"top module1_v1_0_S00_AXI_inst axi_wready",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+20,"top module1_v1_0_S00_AXI_inst axi_bresp",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 1,0);
        tracep->declBit(c+21,"top module1_v1_0_S00_AXI_inst axi_bvalid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+22,"top module1_v1_0_S00_AXI_inst axi_araddr",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 5,0);
        tracep->declBit(c+23,"top module1_v1_0_S00_AXI_inst axi_arready",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+24,"top module1_v1_0_S00_AXI_inst axi_rdata",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBus(c+25,"top module1_v1_0_S00_AXI_inst axi_rresp",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 1,0);
        tracep->declBit(c+26,"top module1_v1_0_S00_AXI_inst axi_rvalid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+97,"top module1_v1_0_S00_AXI_inst ADDR_LSB",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+98,"top module1_v1_0_S00_AXI_inst OPT_MEM_ADDR_BITS",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+27,"top module1_v1_0_S00_AXI_inst slv_reg16",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBit(c+87,"top module1_v1_0_S00_AXI_inst slv_reg_rden",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+62,"top module1_v1_0_S00_AXI_inst slv_reg_wren",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+88,"top module1_v1_0_S00_AXI_inst reg_data_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBus(c+99,"top module1_v1_0_S00_AXI_inst byte_index",-1, FST_VD_IMPLICIT,FST_VT_VCD_INTEGER, false,-1, 31,0);
        tracep->declBit(c+28,"top module1_v1_0_S00_AXI_inst aw_en",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst axi_reset",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo1 width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo1 els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo1 harden_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo1 ready_THEN_valid_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo1 clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+74,"top module1_v1_0_S00_AXI_inst u_fifo1 v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+2,"top module1_v1_0_S00_AXI_inst u_fifo1 ready_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+4,"top module1_v1_0_S00_AXI_inst u_fifo1 data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+6,"top module1_v1_0_S00_AXI_inst u_fifo1 v_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+8,"top module1_v1_0_S00_AXI_inst u_fifo1 data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+10,"top module1_v1_0_S00_AXI_inst u_fifo1 yumi_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ready_THEN_valid_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+74,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+2,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ready_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+4,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+6,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo v_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+8,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+10,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo yumi_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+10,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo deque",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+6,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo v_o_tmp",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+63,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo enque",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+2,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ready_lo",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+29,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo rptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+30,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo wptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBit(c+31,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo full",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+32,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo empty",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+63,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft enq_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+10,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft deq_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+30,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr_r_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+29,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr_r_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+33,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr_n_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+31,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft full_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+32,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft empty_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+29,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+33,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr_n",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+30,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBit(c+34,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft enq_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+35,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft deq_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+32,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft empty",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+31,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft full",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+36,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft equal_ptrs",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr slots_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr max_add_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+10,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr add_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+29,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+33,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr n_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+29,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr ptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+33,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr ptr_n",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+37,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr ptr_nowrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+38,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft rptr ptr_wrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr slots_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr max_add_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+63,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr add_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+30,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+90,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr n_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+30,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr ptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+90,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr ptr_n",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+91,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr ptr_nowrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+64,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo ft wptr ptr_wrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w read_write_same_addr_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w addr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w harden_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w w_clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w w_reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+63,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w w_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+30,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w w_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+4,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w w_data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+6,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w r_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+29,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w r_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+8,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w r_data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth read_write_same_addr_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth addr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth harden_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth w_clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth w_reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+63,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth w_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+30,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth w_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+4,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth w_data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+6,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth r_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+29,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth r_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+8,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth r_data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth unused0",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+6,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth unused1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        {int i; for (i=0; i<5; i++) {
                tracep->declBus(c+39+i*1,"top module1_v1_0_S00_AXI_inst u_fifo1 unhardened un fifo mem_1r1w synth nz mem",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);}}
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_free_cnt els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_free_cnt count_free_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_free_cnt ready_THEN_valid_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_free_cnt ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_free_cnt clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_free_cnt reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+74,"top module1_v1_0_S00_AXI_inst u_free_cnt v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+2,"top module1_v1_0_S00_AXI_inst u_free_cnt ready_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+10,"top module1_v1_0_S00_AXI_inst u_free_cnt yumi_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+11,"top module1_v1_0_S00_AXI_inst u_free_cnt count_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+92,"top module1_v1_0_S00_AXI_inst u_free_cnt enque",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter max_val_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter init_val_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter max_step_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter step_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+10,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter up_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+92,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter down_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+11,"top module1_v1_0_S00_AXI_inst u_free_cnt gen_blk_0 counter count_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo2 width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo2 els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo2 harden_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo2 ready_THEN_valid_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo2 clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+1,"top module1_v1_0_S00_AXI_inst u_fifo2 v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+3,"top module1_v1_0_S00_AXI_inst u_fifo2 ready_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+5,"top module1_v1_0_S00_AXI_inst u_fifo2 data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+7,"top module1_v1_0_S00_AXI_inst u_fifo2 v_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+9,"top module1_v1_0_S00_AXI_inst u_fifo2 data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+86,"top module1_v1_0_S00_AXI_inst u_fifo2 yumi_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ready_THEN_valid_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+1,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+3,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ready_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+5,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+7,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo v_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+9,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+86,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo yumi_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+86,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo deque",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+7,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo v_o_tmp",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+44,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo enque",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+3,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ready_lo",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+45,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo rptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+46,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo wptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBit(c+47,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo full",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+48,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo empty",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+44,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft enq_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+86,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft deq_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+46,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr_r_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+45,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr_r_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+93,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr_n_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+47,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft full_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+48,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft empty_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+45,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+93,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr_n",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+46,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBit(c+49,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft enq_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+50,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft deq_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+48,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft empty",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+47,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft full",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBit(c+51,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft equal_ptrs",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr slots_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr max_add_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+86,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr add_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+45,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+93,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr n_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+45,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr ptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+93,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr ptr_n",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+94,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr ptr_nowrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+65,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft rptr ptr_wrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr slots_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr max_add_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+44,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr add_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+46,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+52,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr n_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+46,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr ptr_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+52,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr ptr_n",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+53,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr ptr_nowrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+54,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo ft wptr ptr_wrap",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w read_write_same_addr_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w addr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w harden_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w w_clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w w_reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+44,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w w_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+46,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w w_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+5,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w w_data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+7,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w r_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+45,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w r_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+9,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w r_data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBus(c+100,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth width_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth read_write_same_addr_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth addr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth harden_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth w_clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth w_reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+44,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth w_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+46,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth w_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+5,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth w_data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+7,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth r_v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+45,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth r_addr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+9,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth r_data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth unused0",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+7,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth unused1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
        {int i; for (i=0; i<5; i++) {
                tracep->declBus(c+55+i*1,"top module1_v1_0_S00_AXI_inst u_fifo2 unhardened un fifo mem_1r1w synth nz mem",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);}}
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_avail_cnt els_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_avail_cnt count_free_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_avail_cnt ready_THEN_valid_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_avail_cnt ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_avail_cnt clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_avail_cnt reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+1,"top module1_v1_0_S00_AXI_inst u_avail_cnt v_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+3,"top module1_v1_0_S00_AXI_inst u_avail_cnt ready_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+86,"top module1_v1_0_S00_AXI_inst u_avail_cnt yumi_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+12,"top module1_v1_0_S00_AXI_inst u_avail_cnt count_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+60,"top module1_v1_0_S00_AXI_inst u_avail_cnt enque",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+101,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter max_val_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+102,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter init_val_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter max_step_p",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+104,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter step_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBus(c+103,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter ptr_width_lp",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 31,0);
        tracep->declBit(c+66,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+89,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter reset_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+60,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter up_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+86,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter down_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
        tracep->declBus(c+12,"top module1_v1_0_S00_AXI_inst u_avail_cnt gen_blk_0 counter count_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    }
}

void Vtop::traceRegister(VerilatedFst* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i));
        tracep->fullBit(oldp+2,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
        tracep->fullBit(oldp+3,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
        tracep->fullIData(oldp+4,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_data_i),32);
        tracep->fullIData(oldp+5,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_i),32);
        tracep->fullBit(oldp+6,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)))));
        tracep->fullBit(oldp+7,((1U & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty)))));
        tracep->fullIData(oldp+8,(((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r))
                                    ? vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                                   [vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r]
                                    : 0U)),32);
        tracep->fullIData(oldp+9,(((4U >= (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r))
                                    ? vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem
                                   [vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r]
                                    : 0U)),32);
        tracep->fullBit(oldp+10,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i));
        tracep->fullCData(oldp+11,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__free_cnt),3);
        tracep->fullCData(oldp+12,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__avail_cnt),3);
        tracep->fullCData(oldp+13,((0xffU & vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16)),8);
        tracep->fullCData(oldp+14,((0xffU & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                             >> 0x10U))),8);
        tracep->fullCData(oldp+15,((((0xffU & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                               >> 0x10U)) 
                                     >= (0xffU & vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16))
                                     ? 0U : (0xffU 
                                             & (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                                - (vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16 
                                                   >> 0x10U))))),8);
        tracep->fullCData(oldp+16,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__cnt),8);
        tracep->fullCData(oldp+17,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awaddr),6);
        tracep->fullBit(oldp+18,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_awready));
        tracep->fullBit(oldp+19,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_wready));
        tracep->fullCData(oldp+20,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bresp),2);
        tracep->fullBit(oldp+21,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_bvalid));
        tracep->fullCData(oldp+22,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr),6);
        tracep->fullBit(oldp+23,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready));
        tracep->fullIData(oldp+24,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rdata),32);
        tracep->fullCData(oldp+25,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rresp),2);
        tracep->fullBit(oldp+26,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid));
        tracep->fullIData(oldp+27,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg16),32);
        tracep->fullBit(oldp+28,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__aw_en));
        tracep->fullCData(oldp+29,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r),3);
        tracep->fullCData(oldp+30,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r),3);
        tracep->fullBit(oldp+31,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full));
        tracep->fullBit(oldp+32,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty));
        tracep->fullCData(oldp+33,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap))
                                           ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                              + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i))
                                           : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap)))),3);
        tracep->fullBit(oldp+34,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
        tracep->fullBit(oldp+35,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
        tracep->fullBit(oldp+36,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs));
        tracep->fullCData(oldp+37,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                          + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f1_yumi_i)))),3);
        tracep->fullCData(oldp+38,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap),4);
        tracep->fullIData(oldp+39,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[0]),32);
        tracep->fullIData(oldp+40,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[1]),32);
        tracep->fullIData(oldp+41,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[2]),32);
        tracep->fullIData(oldp+42,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[3]),32);
        tracep->fullIData(oldp+43,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[4]),32);
        tracep->fullBit(oldp+44,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque));
        tracep->fullCData(oldp+45,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r),3);
        tracep->fullCData(oldp+46,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r),3);
        tracep->fullBit(oldp+47,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full));
        tracep->fullBit(oldp+48,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__empty));
        tracep->fullBit(oldp+49,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__enq_r));
        tracep->fullBit(oldp+50,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__deq_r));
        tracep->fullBit(oldp+51,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__equal_ptrs));
        tracep->fullCData(oldp+52,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap))
                                           ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                              + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque))
                                           : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap)))),3);
        tracep->fullCData(oldp+53,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                          + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)))),3);
        tracep->fullCData(oldp+54,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap),4);
        tracep->fullIData(oldp+55,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[0]),32);
        tracep->fullIData(oldp+56,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[1]),32);
        tracep->fullIData(oldp+57,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[2]),32);
        tracep->fullIData(oldp+58,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[3]),32);
        tracep->fullIData(oldp+59,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__mem_1r1w__DOT__synth__DOT__nz__DOT__mem[4]),32);
        tracep->fullBit(oldp+60,(((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_v_i) 
                                  & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
        tracep->fullIData(oldp+61,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__f2_data_o_mod),32);
        tracep->fullBit(oldp+62,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__slv_reg_wren));
        tracep->fullBit(oldp+63,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque));
        tracep->fullCData(oldp+64,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap),4);
        tracep->fullCData(oldp+65,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap),4);
        tracep->fullBit(oldp+66,(vlTOPp->s00_axi_aclk));
        tracep->fullBit(oldp+67,(vlTOPp->s00_axi_aresetn));
        tracep->fullCData(oldp+68,(vlTOPp->s00_axi_awaddr),6);
        tracep->fullCData(oldp+69,(vlTOPp->s00_axi_awprot),3);
        tracep->fullBit(oldp+70,(vlTOPp->s00_axi_awvalid));
        tracep->fullBit(oldp+71,(vlTOPp->s00_axi_awready));
        tracep->fullIData(oldp+72,(vlTOPp->s00_axi_wdata),32);
        tracep->fullCData(oldp+73,(vlTOPp->s00_axi_wstrb),4);
        tracep->fullBit(oldp+74,(vlTOPp->s00_axi_wvalid));
        tracep->fullBit(oldp+75,(vlTOPp->s00_axi_wready));
        tracep->fullCData(oldp+76,(vlTOPp->s00_axi_bresp),2);
        tracep->fullBit(oldp+77,(vlTOPp->s00_axi_bvalid));
        tracep->fullBit(oldp+78,(vlTOPp->s00_axi_bready));
        tracep->fullCData(oldp+79,(vlTOPp->s00_axi_araddr),6);
        tracep->fullCData(oldp+80,(vlTOPp->s00_axi_arprot),3);
        tracep->fullBit(oldp+81,(vlTOPp->s00_axi_arvalid));
        tracep->fullBit(oldp+82,(vlTOPp->s00_axi_arready));
        tracep->fullIData(oldp+83,(vlTOPp->s00_axi_rdata),32);
        tracep->fullCData(oldp+84,(vlTOPp->s00_axi_rresp),2);
        tracep->fullBit(oldp+85,(vlTOPp->s00_axi_rvalid));
        tracep->fullBit(oldp+86,(vlTOPp->s00_axi_rready));
        tracep->fullBit(oldp+87,((((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_arready) 
                                   & (IData)(vlTOPp->s00_axi_arvalid)) 
                                  & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_rvalid)))));
        tracep->fullIData(oldp+88,(((0x20U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__axi_araddr))
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
        tracep->fullBit(oldp+89,((1U & (~ (IData)(vlTOPp->s00_axi_aresetn)))));
        tracep->fullCData(oldp+90,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap))
                                           ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                              + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque))
                                           : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_wrap)))),3);
        tracep->fullCData(oldp+91,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__wptr__DOT__ptr_r) 
                                          + (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__enque)))),3);
        tracep->fullBit(oldp+92,(((IData)(vlTOPp->s00_axi_wvalid) 
                                  & (~ (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo1__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__full)))));
        tracep->fullCData(oldp+93,((7U & ((8U & (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap))
                                           ? ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                              + (IData)(vlTOPp->s00_axi_rready))
                                           : (IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_wrap)))),3);
        tracep->fullCData(oldp+94,((7U & ((IData)(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__u_fifo2__DOT__unhardened__DOT__un__DOT__fifo__DOT__ft__DOT__rptr__DOT__ptr_r) 
                                          + (IData)(vlTOPp->s00_axi_rready)))),3);
        tracep->fullIData(oldp+95,(0x20U),32);
        tracep->fullIData(oldp+96,(6U),32);
        tracep->fullIData(oldp+97,(2U),32);
        tracep->fullIData(oldp+98,(3U),32);
        tracep->fullIData(oldp+99,(vlTOPp->top__DOT__module1_v1_0_S00_AXI_inst__DOT__byte_index),32);
        tracep->fullIData(oldp+100,(0x20U),32);
        tracep->fullIData(oldp+101,(5U),32);
        tracep->fullIData(oldp+102,(0U),32);
        tracep->fullIData(oldp+103,(3U),32);
        tracep->fullIData(oldp+104,(1U),32);
    }
}
