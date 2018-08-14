#!/bin/bash
# replace multiple files' extensions
old_ext=
new_ext=

while getopts o:n: ARG
do
    case $ARG in
	# d)
	#     directory=$OPTARG
	#     ;;
	o)
	    old_ext=.$OPTARG
	    ;;
	n)
	    new_ext=.$OPTARG
	    ;;
	*)
	    echo "Unknown options"
	    exit 1
	    ;;
    esac
done

shift "$((OPTIND-1))"

directory='.'

if [ $1 ];then
    directory=$1
fi

replace_ext()
{
    if [ ! -d $directory ];then
	echo "No such directory"
	exit 1
    fi
    if [ ! $old_ext ];then
	echo "Option -o is required"
	exit 1
    fi
    if [ ! $new_ext ];then
	echo "Option -n is required"
	exit 1
    fi
    for file in `ls ${directory} | grep ${old_ext}`
    do
	echo "${directory}/${file}"
	mv "${directory}/${file}" $(echo "${directory}/${file}" | sed "s/${old_ext}/${new_ext}/")
    done
}

replace_ext
