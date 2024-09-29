.section .data
  # 4 + 2 + 2 + 2 + 1 + 5 (padding)
  .equ DEV_READINGS_OFFSET, 16
  # 4 + 2 + 2 + 2
  .equ N_READINGS_OFFSET, 10

  .equ PRESSURE_MASK, 0x3FF00000
  .equ HUMIDITY_MASK, 0x000FFC00
  .equ TEMP_MASK,     0x000003FF

  .equ TEMP_MAX_OFFSET, 4
  .equ HUM_MAX_OFFSET, 6
  .equ PRESS_MAX_OFFSET, 8
.section .text 
  .global device_max # int device_max(device_info *device, unsigned char sensor_type)

device_max:            
# rdi -> *device 
# rsi -> sensor_type
  
  movq DEV_READINGS_OFFSET(%rdi), %r8 # get address to dev_readings
  movb N_READINGS_OFFSET(%rdi), %cl # get n_readings
  movsbq %cl, %rcx # cast to quad

  xorl %eax, %eax # set greatest as 0 (as values are unsigned)
 
  cmpb $2, %sil # as sensor_type cannot be negative, only comparison with > is needed
  ja .invalid
  
  testb %sil, %sil
  je .temperature

  cmpb $1, %sil
  je .humidity

  movl $PRESSURE_MASK, %r9d # default case (as exceptions are already checked)

  .continue:
    .loop: # iterate for each element in dev_readings
      leaq (%r8, %rcx, 4), %r10
      movl (%r10), %r10d
      andl %r9d, %r10d # value of interest

      # if r9d has temp mask, nothing is needed, otherwise shifts are used

      cmpb $2, %sil
      je .pressure_shifts

      cmpb $1, %sil
      je .humidity_shifts

      .c1:
        cmpl %r10d, %eax
        cmpl %eax, %r10d
        jg .greater
        .c3:
    loop .loop

    # max value is in %eax
    testb %sil, %sil
    je .temp_max

    cmpb $1, %sil
    je .humd_max

    # could be better
    movw %ax, PRESS_MAX_OFFSET(%rdi) # default case (as exceptions are already checked)

  .c2:
    movl $1, %eax
    jmp .end
.greater:
  movl %r10d, %eax
  jmp .c3
.temperature:
  movl $TEMP_MASK, %r9d
  jmp .continue
.humidity:
  movl $HUMIDITY_MASK, %r9d
  jmp .continue
.pressure_shifts:
  shrl $20, %r10d
  jmp .c1
.humidity_shifts:
  shrl $10, %r10d
  jmp .c1
.temp_max:
  movw %ax, TEMP_MAX_OFFSET(%rdi) # default case (as exceptions are already checked)
  jmp .c2
.humd_max:
  movw %ax, HUM_MAX_OFFSET(%rdi) # default case (as exceptions are already checked)
  jmp .c2
.invalid:
  movl $0, %eax
.end:
  ret
