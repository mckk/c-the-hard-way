echo "Running unit tests:"

for i in tests/*_tests
do
  if test -f $i
  then
    if ./$i
    then
      echo $i PASS
    else
      echo "ERROR in test $i"
      exit 1
    fi
  fi
done

echo ""
