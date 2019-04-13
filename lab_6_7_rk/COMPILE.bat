MASM /Zi main.txt,,,;
MASM /Zi scan.txt,,,;
MASM /Zi signed.txt,,,; 
MASM /Zi 1.txt,,,;  
LINK /CO main.obj scan.obj signed.obj 1.obj,,;

del *.MAP
del *.CRF
del *.LST
del *.OBJ
