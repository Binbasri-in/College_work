    AREA ABC,CODE,READONLY

    LDR R0,=ARRAY
    MOV R2,#0

AGAIN
    LDRH R1,[R0],#2
    ADD R2,R1
    CMP R1,#0
    BNE AGAIN
    LDR R3,=RESULT
    STR R2,[R3]

LOOP B LOOP

ARRAY DCW 0x1111, 0x2222, 0x3333, 0x4444, 0x5555
ARRAYEND DCW 0
    ALIGN

    AREA DES,DATA,READWRITE
RESULT DCD 0
    END