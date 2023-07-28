      AREA FACTORIAL,CODE,READONLY
START
    MOV R0,#10  ; R0 = 10
    MOV R1,#0   ; R1 = 0

AGAIN
    MUL R1,R0,R1   ; R1 = R0 * R1
    SUB R0,#1   ; R0 = R0 - 1
    CMP R0,#0   ; R0 - 0 == 0?
    BNE AGAIN   ; if not equal, jump to AGAIN

LOOP B LOOP ; infinite loop

    END