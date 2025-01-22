FetchContent_Declare(pntr_brush
  URL https://github.com/RobLoach/pntr_brush/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(pntr_brush)
include_directories(${pntr_brush_SOURCE_DIR})
