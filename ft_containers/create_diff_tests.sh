#/bin/bash

if [ "$1" == "clear" ]; then
    rm -rf test_results
else
    echo "(FT) Running all vector tests..."

    mkdir -p test_results
    FT_VECTOR_TARGET="test_results/ft_vector_tests"
    ./ft_container 0 0 > $FT_VECTOR_TARGET
    echo "-----DONE------" >> $FT_VECTOR_TARGET
    ./ft_container 0 1 >> $FT_VECTOR_TARGET
    echo "-----DONE------" >> $FT_VECTOR_TARGET
    ./ft_container 0 2 >> $FT_VECTOR_TARGET
    echo "-----DONE------" >> $FT_VECTOR_TARGET
    ./ft_container 0 3 >> $FT_VECTOR_TARGET
    echo "-----DONE------" >> $FT_VECTOR_TARGET
    ./ft_container 0 4 >> $FT_VECTOR_TARGET
    echo "-----ALL DONE------" >> $FT_VECTOR_TARGET

    echo "(STD) Running all vector tests..."

    STD_VECTOR_TARGET="test_results/std_vector_tests"
    ./std_container 0 0 > $STD_VECTOR_TARGET
    echo "-----DONE------" >> $STD_VECTOR_TARGET
    ./std_container 0 1 >> $STD_VECTOR_TARGET
    echo "-----DONE------" >> $STD_VECTOR_TARGET
    ./std_container 0 2 >> $STD_VECTOR_TARGET
    echo "-----DONE------" >> $STD_VECTOR_TARGET
    ./std_container 0 3 >> $STD_VECTOR_TARGET
    echo "-----DONE------" >> $STD_VECTOR_TARGET
    ./std_container 0 4 >> $STD_VECTOR_TARGET
    echo "-----ALL DONE------" >> $STD_VECTOR_TARGET

    echo "(VECTOR) checking diff between ft and std..."
    diff $FT_VECTOR_TARGET $STD_VECTOR_TARGET > test_results/diff_vector

    echo "(FT) Running all map tests..."

    FT_MAP_TARGET="test_results/ft_map_tests"
    ./ft_container 1 0 > $FT_MAP_TARGET
    echo "-----DONE------" >> $FT_MAP_TARGET
    ./ft_container 1 1 >> $FT_MAP_TARGET
    echo "-----DONE------" >> $FT_MAP_TARGET
    ./ft_container 1 2 >> $FT_MAP_TARGET
    echo "-----DONE------" >> $FT_MAP_TARGET
    ./ft_container 1 3 >> $FT_MAP_TARGET
    echo "-----DONE------" >> $FT_MAP_TARGET
    ./ft_container 1 4 >> $FT_MAP_TARGET
    echo "-----ALL DONE------" >> $FT_MAP_TARGET

    echo "(STD) Running all map tests..."

    STD_MAP_TARGET="test_results/std_map_tests"
    ./std_container 1 0 > $STD_MAP_TARGET
    echo "-----DONE------" >> $STD_MAP_TARGET
    ./std_container 1 1 >> $STD_MAP_TARGET
    echo "-----DONE------" >> $STD_MAP_TARGET
    ./std_container 1 2 >> $STD_MAP_TARGET
    echo "-----DONE------" >> $STD_MAP_TARGET
    ./std_container 1 3 >> $STD_MAP_TARGET
    echo "-----DONE------" >> $STD_MAP_TARGET
    ./std_container 1 4 >> $STD_MAP_TARGET
    echo "-----ALL DONE------" >> $STD_MAP_TARGET

    echo "(MAP) checking diff between ft and std..."
    diff $FT_MAP_TARGET $STD_MAP_TARGET > test_results/diff_map

    echo "(FT) Running all stack tests..."

    FT_STACK_TARGET="test_results/ft_stack_tests"
    ./ft_container 2 0 > $FT_STACK_TARGET
    echo "-----DONE------" >> $FT_STACK_TARGET
    ./ft_container 2 1 >> $FT_STACK_TARGET
    echo "-----DONE------" >> $FT_STACK_TARGET
    ./ft_container 2 2 >> $FT_STACK_TARGET
    echo "-----ALL DONE------" >> $FT_STACK_TARGET

    echo "(STD) Running all stack tests..."

    STD_STACK_TARGET="test_results/std_stack_tests"
    ./std_container 2 0 > $STD_STACK_TARGET
    echo "-----DONE------" >> $STD_STACK_TARGET
    ./std_container 2 1 >> $STD_STACK_TARGET
    echo "-----DONE------" >> $STD_STACK_TARGET
    ./std_container 2 2 >> $STD_STACK_TARGET
    echo "-----ALL DONE------" >> $STD_STACK_TARGET

    echo "(STACK) checking diff between ft and std..."
    diff $FT_STACK_TARGET $STD_STACK_TARGET > test_results/diff_stack

fi