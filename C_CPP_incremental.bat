cd C:\Developing\Klocwork\Server 18.2\bin

	
kwinject --update StudentManager.out "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\devenv" "C:\Users\Cao Feng\Documents\Develop_file\VS\StudentManager\StudentManager.sln" /Rebuild
kwbuildproject --url http://localhost:8090/StudentManager --tables-directory "C:\Users\Cao Feng\Documents\Develop_file\Klockwork\my_tables\StudentManager" --force StudentManager.out 
kwadmin --url http://localhost:8090/ load StudentManager "C:\Users\Cao Feng\Documents\Develop_file\Klockwork\my_tables\StudentManager"