const swap = function(or,oc,tr, tc){
    [this[or][oc],this[tr][tc]] = [this[tr][tc],this[or][oc]];
};
let totalLevel = Math.floor(matrix.length/2);
let last = matrix.length-1;
let level = 0;
while(level<totalLevel){
    for(let i=level; i<=last-1; i++){
        swap.apply(matrix, [level,i,i,last]); // swap from left top to right top
        swap.apply(matrix, [level,i,last,last-i+level]);
        swap.apply(matrix, [level,i,last-i+level,level])
    }
    ++level;
    --last;
}
