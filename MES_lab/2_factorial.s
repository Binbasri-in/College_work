      AREA FACTORIAL,CODE,READONLY
START
    MOV R0,#10  ; R0 = 10
    MOV R1,R0   ; R1 = 10

AGAIN
    SUB R0,#1   ; R0 = R0 - 1
    MUL R1,R0,R1   ; R1 = R0 * R1
    CMP R0,#1   ; R0 - 0 == 0?
    BNE AGAIN   ; if not equal, jump to AGAIN

LOOP B LOOP ; infinite loop

    END
