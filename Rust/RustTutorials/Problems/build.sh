#!/usr/bin/zsh

file=$1  # Use $1 as the filename
fmt=""   # Use $2 as the format flag
run=""   # Use $3 as the run flag
ntimes="" # Use $4 as the how many time you want to run the code while flag

#Parse command-line Arguments
shift # Shift to next argument $1=$2 ,$2=$3...

while [[ "$#" -gt 0 ]]; do # $# is going give the number of positional argument passed 
    case "$1" in
        -y|--format) fmt="-y" ;;
        -r|--run) run="-r"; ntimes="$2"; shift ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift  # Move to the next argument
done

#Text Forxmating block
if [[ "$fmt" == "-y" ]]; then
    rustfmt "$file"
    echo "Text formatting: Done"
fi


#Run block
if [[ "$run" == "-r" ]]; then
    rustc "$file" -o "${file%.*}"  # Compile and specify output file

    while [[ $ntimes -ge 1 ]]; do  
        "./${file%.*}" 
	echo
        ntimes=$(expr $ntimes - 1) 
    done
    rm -f "${file%.*}" # Remove compiled output file
fi

