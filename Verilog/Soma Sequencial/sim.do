if {[file isdirectory work]} { vdel -all -lib work }
vlib work
vmap work work

vlog -work work ex3.v
vlog -work work tb.v

vsim -voptargs=+acc=lprn -t ns work.tb

set StdArithNoWarnings 1
set StdVitalGlitchNoWarnings 1

do wave.do 

run 300 ns
