#!/bin/bash

create_files(){
    path=$1
    name=$2
    file_type=$3
    new_path="${path}/${name}_${file_type}"
    
    if [[ "${file_type}" == "cpp" || "${file_type}" == "py" || "${file_type}" == "java" ]]; then
        echo "creating file : ${file_type}"
        mkdir ${new_path}
        touch ${new_path}/main.${file_type}
        cd ${path}

    elif [[ "${file_type}" == "rust" ]]; then
        echo "creating file : ${file_type}"
        cd ${path}
        cargo new "${name}_${file_type}"
        cd ${path}

    elif [[ "${file_type}" == "go" ]]; then
        echo "creating file : ${file_type}"
        mkdir ${new_path}
        cd ${new_path}
        go mod init "${name}_${file_type}"
        touch "main.go"
        cd ${path}
    fi

    
}


folderName=$1

path="$(pwd)/${folderName}"

mkdir "${path}"
if [[ -d ${path} ]]; then
    echo "file already exist"
else 
    echo "creating a new directory of folderName : ${folderName}"
    mkdir "${path}"
fi

files=("cpp" "py" "rust" "go" "java")
declare -A path_to_files


for file in "${files[@]}"; do
    echo "$file"
    create_files ${path} ${folderName} $file
    
done

echo $(pwd)

touch "${path}/problem_statment.md" "${path}/algo_solution.md"

var=`cat << EOF
# Topic Name

- [Problem Statement](./problem_statment.md)
- [Algorithmic solution along with theory](./algo_solution.md)


- [C++ Solution](./${folderName}_cpp/main.cpp)
- [Python Solution](./${folderName}_py/main.py)
- [Java Solution](./${folderName}_java/main.java)
- [Rust Solution](./${folderName}_rust/src/main.rs)
- [Go Solution](./${folderName}_go/main.go)
EOF
`

echo ${path}
touch "${path}/README.md"
echo "${var}" > "${path}/README.md"
