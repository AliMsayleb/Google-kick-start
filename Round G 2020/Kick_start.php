<?php

// Question can be found here: https://codingcompetitions.withgoogle.com/kickstart/round/00000000001a0069/0000000000414bfb
// Solved in PHP because in cpp i had a problem with reading the end of line. it was jumping to the line from other test cases.
// But it's the same algorithm and same implementation

function readline(){
    $fp = fopen("php://stdin","r");
    return rtrim(fgets($fp, 100000));
}

$cases = (int) readline();

for ($i = 1; $i <= $cases; $i++) {
    $line = readline();
    $kicks = 0;
    $total = 0;
    for ($j = 0; $j < strlen($line) - 4; $j++) {
        if ($line[$j] == 'K' && $line[$j+1] == 'I' && $line[$j+2] == 'C' && $line[$j+3] == 'K') {
            $kicks++;
            $j += 3;
        } else if ($line[$j] == 'S' && $line[$j+1] == 'T' && $line[$j+2] == 'A' && $line[$j+3] == 'R' && $line[$j+4] == 'T') {
            $total += $kicks;
            $j += 4;
        }
    }
    
    echo "Case #$i: $total".PHP_EOL;
}
