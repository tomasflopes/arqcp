void changes(int *ptr)
{
  int second_byte_mask = 0x0000ff00; 
  int third_byte_mask = 0x00ff0000;

  int second_byte = *ptr & second_byte_mask;

  second_byte >>= 8; // shifts second_byte to first position to read real value
                    
  if(second_byte > 15)
    *ptr ^= third_byte_mask; // xor inverts bits
}
