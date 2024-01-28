transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/thirty_two_bit_subtractor.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/thirty_two_bit_adder.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/ALU.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/four_bit_CLA.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/four_bit_CLL.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/is_less_than.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/my_xor.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/my_twos_complement.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/my_or.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/my_nor.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/my_and.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/mod_dp.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/mod_cu.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/mod.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/one_bit_adder.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/second_level_CLL.v}
vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/_8x1Mux.v}

vlog -vlog01compat -work work +incdir+/home/aksoy/Desktop/BedirhanOmerAksoy_HW2 {/home/aksoy/Desktop/BedirhanOmerAksoy_HW2/ALU_testbench.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cyclonev_ver -L cyclonev_hssi_ver -L cyclonev_pcie_hip_ver -L rtl_work -L work -voptargs="+acc"  ALU_testbench

add wave *
view structure
view signals
run -all
