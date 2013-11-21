echo "Running unit tests:"

for i in tests/*_test
do
  if test -f $i
  then
    if ./$i $1
    then
      echo $i PASS
    else
      echo "ERROR in test $i"
      exit 1
    fi
  fi
done

echo ""
