.section .data
.section .text 
  .global global_max # int global_max(device_info *devices, int n_devices, unsigned char sensor_type)

global_max:            
# rdi -> *device 
# rsi -> n_devices
# rdx -> sensor_type
  xorl %eax, %eax # start max as 0 as values are unsigned
  movq %rsi, %rcx # get n_devices
  .loop:
    leaq (%rdi, %rcx, 8), %r8
    pushq %rdi
    pushq %rsi
    pushq %rdx
      movq (%r8), %rdi
      movq %rdx, %rsi
      call device_max

      # get value of max and then compare to global max %eax, no time
    popq %rdx
    popq %rsi
    popq %rdi
  loop .loop

  ret
  
