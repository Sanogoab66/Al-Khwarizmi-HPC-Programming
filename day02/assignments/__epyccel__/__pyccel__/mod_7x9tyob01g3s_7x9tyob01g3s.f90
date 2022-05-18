module mod_7x9tyob01g3s_7x9tyob01g3s


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function factorial_itr(n) result(k)

    implicit none

    integer(i64) :: k
    integer(i64), value :: n
    integer(i64) :: i

    k = 1_i64
    do i = 1_i64, n + 1_i64 - 1_i64, 1_i64
      k = k * i
    end do
    return

  end function factorial_itr
  !........................................

end module mod_7x9tyob01g3s_7x9tyob01g3s