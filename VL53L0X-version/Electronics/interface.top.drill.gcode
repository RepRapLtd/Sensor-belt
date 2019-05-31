;(.../Electronics/Eagle/pcb-gcode/pcb-gcode.ulp)
;(Copyright 2005 - 2012 by John Johnson)
;(See readme.txt for licensing terms.)
;(This file generated from the board:)
;(.../VL53L0X-version/Electronics/interface.brd)
;(Current profile is .../pcb-gcode/profiles/generic.pp  )
;(This file generated 30/05/2019 16:26)
;(Settings from pcb-machine.h)
;(spindle on time = 1000.0000)
;(spindle speed = 20000.0000)
;(tool change at 0.0000 0.0000 5.0000 )
;(feed rate xy = F0.00  )
;(feed rate z  = F200.00 )
;(Z Axis Settings)
;(  High     Up        Down     Drill)
;(5.0000 	2.0000 	-0.2000 	-2.0000 )
;(Settings from pcb-defaults.h)
;(isolate min = 0.0250)
;(isolate max = 0.5000)
;(isolate step = 0.0800)
;(Generated top outlines, top drill, )
;(Unit of measure: mm)
;( Tool|       Size       |  Min Sub |  Max Sub |   Count )
;( T01  0.600mm 0.0236in 0.0000in 0.0000in )
;( T02  1.016mm 0.0400in 0.0000in 0.0000in )
;(Metric Mode)
G21
;(Absolute Coordinates)
G90
;S20000
G00 Z5.0000  F3000
G00 X0.0000 Y0.0000  F3000
;M03 S1
G04 P1000.000000
;M03 S0
;M06 T01  ; 0.6000 
G01 Z0.0000 F200.00 
;M06 
G00 Z2.0000  F3000
;M03 S1
G04 P1000.000000
G00 X3.0000 Y3.0000  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X3.0000 Y16.0000  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
;M03 S0
G00 Z5.0000  F3000
G00 X0.0000 Y0.0000  F3000
;M06 T02  ; 1.0160 
G01 Z0.0000 F200.00 
;M06 
G00 Z2.0000  F3000
;M03 S1
G04 P1000.000000
G00 X3.0300 Y10.0800  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X5.5700 Y10.0800  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X7.6200 Y2.5400  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X10.1600 Y2.5400  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X12.7000 Y2.5400  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X15.2400 Y2.5400  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X17.7800 Y2.5400  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X17.7800 Y16.5100  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X15.2400 Y16.5100  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X12.7000 Y16.5100  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
G00 X10.1600 Y16.5100  F3000
G01 Z-2.0000 F200.00 
G00 Z2.0000  F3000
;T01 
G00 Z5.0000  F3000
;M03 S0
M0
