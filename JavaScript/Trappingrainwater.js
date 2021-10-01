// Apsara Budathoki
// Trapping rain water
<script>
	function maxWater(arr, n)
	{
		let res = 0;
		for(let i = 1; i < n - 1; i++)
		{
			let left = arr[i];
			for(let j = 0; j < i; j++)
			{
				left = Math.max(left, arr[j]);
			}
			let right = arr[i];
			for(let j = i + 1; j < n; j++)
			{
				right = Math.max(right, arr[j]);
			}
			res += Math.min(left, right) - arr[i];
		}
		return res;
	}
	
	let arr = [ 0, 1, 0, 2, 1, 0,
				1, 3, 2, 1, 2, 1 ];
	let n = arr.length;

	document.write(maxWater(arr,n));
	
</script>

