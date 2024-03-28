 ++++[>++++[>+++<-]<-]   writing 48 / 0x30 / '0' in cell(2) of my array
    ,>,>                    I read two numbers in cell(0) and cell(1)
    [<-<->>-]               i am doing a loop for my function, decrementing cell(0) and cell(1) by 48 / 0x30 / '0'
    <<                      go to cell(0)
    [                       i am entering my mulitplication loop
        >                   this is incrementing for me to go to cell(1) from cell(0)
        [>+>+<<-]           am incrementing cell(1) to cell(2) and cell(3)
        >>                  this is my go to the cell(3)
        [<<+>>-]            i move my cell(3) back to cell(1) by decrementing
        <<<-                decrementing to cell(0)
    ]
    >[-]<                   i am settting my cell(1) to 0 to use it as my loop, at this point I have had to move back to cell(0)
    ++++[>++++[>+++<-]<-]   adding 48 / 0x30 / '0' to cell(2) cell(2) contains my result
    >>.                     after my loop condition return to a zero, the loop will terminate and the . will print result that's contained in cell(2)
