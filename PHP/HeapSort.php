<?php

function heapify(&$arr, $N, $i)
{
	$largest = $i; 
	$l = 2*$i + 1; 
	$r = 2*$i + 2;

	if ($l < $N && $arr[$l] > $arr[$largest])
		$largest = $l;

	if ($r < $N && $arr[$r] > $arr[$largest])
		$largest = $r;

	if ($largest != $i)
	{
		$swap = $arr[$i];
		$arr[$i] = $arr[$largest];
		$arr[$largest] = $swap;

		heapify($arr, $N, $largest);
	}
}

function heapSort(&$arr, $N)
{

	for ($i = $N / 2 - 1; $i >= 0; $i--)
		heapify($arr, $N, $i);

	for ($i = $N-1; $i > 0; $i--)
	{
		$temp = $arr[0];
			$arr[0] = $arr[$i];
			$arr[$i] = $temp;

		heapify($arr, $i, 0);
	}
}

function printArray(&$arr, $N)
{
	for ($i = 0; $i < $N; ++$i)
		echo ($arr[$i]." ") ;
		
}

	$arr = array(12, 11, 13, 5, 6, 7);
	$N = sizeof($arr)/sizeof($arr[0]);
	
	heapSort($arr, $N);

	echo 'Sorted array is ' . "\n";
	
	printArray($arr , $N);

?>
