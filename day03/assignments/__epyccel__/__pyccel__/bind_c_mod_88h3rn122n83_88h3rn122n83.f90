module bind_c_mod_88h3rn122n83_88h3rn122n83

  use mod_88h3rn122n83_88h3rn122n83, only: threads_num

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_threads_num() bind(c) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001

    Out_0001 = threads_num()

  end function bind_c_threads_num
  !........................................

end module bind_c_mod_88h3rn122n83_88h3rn122n83
