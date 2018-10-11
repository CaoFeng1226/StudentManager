cd C:\Developing\Klocwork\Server 18.2\bin

%CREATE AN INTEGRATION PROJECT Or, create using Klocwork Review%
kwadmin --url http://localhost:8090/ create-project StudentManager

%Capture your build settings%
kwinject --output StudentManager.out "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\devenv" "C:\Users\Cao Feng\Documents\Develop_file\VS\StudentManager\StudentManager.sln" /Rebuild

%Run an analysis using the build specification%
kwbuildproject --url http://localhost:8090/StudentManager --tables-directory "C:\Users\Cao Feng\Documents\Develop_file\Klockwork\my_tables\StudentManager" StudentManager.out 

%Load the database%
kwadmin --url http://localhost:8090/ load StudentManager "C:\Users\Cao Feng\Documents\Develop_file\Klockwork\my_tables\StudentManager"