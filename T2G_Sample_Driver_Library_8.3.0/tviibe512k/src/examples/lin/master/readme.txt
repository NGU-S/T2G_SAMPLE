* Board setting
  - Short following pins on the base board:
    If LIN CH0- J59, J60, J61, J62, J63
    If LIN CH1- J52, J53, J54, J55, J56
  - Short J58 (CH0) or J51 (CH1) on the base board if using TVII as a master node
  - Short following pins on the adapter board. (Power suply to base board)
    J150, J151, J152 
  - Connect LIN0 connector (P5 upper one) on the base board
    and CANoe or other analyzer if available.

* Copy main_cm0plus.c or main_cm4.c into your workspace and re-build.
  Both file behave same. Only one of those can be used at once.

* If you have CANoe.LIN, you can use LinConfig_ForMasterTest.cfg for it.
  It's configured as a slave node. It's configured simple test for this example.
  Just run and monitor using trase, statistics window.

