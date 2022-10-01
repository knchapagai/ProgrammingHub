for m in {1..12};
do
  a=$(date -d "$m/1 + 1 month - 1 day" "+%b - %d days";)
  echo "$a"
done 
