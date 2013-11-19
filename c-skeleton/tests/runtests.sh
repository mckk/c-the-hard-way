echo "Running unit tests:"

for i in tests/*_test
do
  if test -f $1
  then
    if $VALGRIND ./%i 2>> tests/tests.log
    then
      echo $1 PASS
    else
      echo "ERROR in test $1: here's tests/tests.log"
      echo "------"
      tail tests/tests.log
      exit 1
    fi
  fi
done

echo ""
