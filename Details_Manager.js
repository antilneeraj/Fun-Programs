/*
JavaScript Program To Manage Details of Students Temporarily
Author : Neeraj
Date : July 22, 2022
*/
function start(){
  let choice;
  let adm_no;
  let flag = 0;
  const parentRecord={};
  
  do{
  console.log("\n\t\t::::SELECTION MENU::::\n1. Show Data\n2. Enter Data\n3. Exit");
  choice = parseInt(prompt("Enter Choice (1/2/3) :"));
  
  switch(choice){
    case 1:
      if(flag != 0)
      {
        adm_no = prompt("Enter Admission no. :");
        if(parentRecord[adm_no])
        {
          console.log(parentRecord[adm_no]);
        }
        else{
          console.log("--------------------------------\nRecord Not Found!\n--------------------------------");
        }
      }
      else{
       console.log("--------------------------------\nThe Record Is Empty!\n--------------------------------");
      }
      break;
    case 2:
      flag = 1;
      parentRecord[prompt("Enter your Admission no. : ")] = {
        name: prompt("Enter your name : "),
        fathersName: prompt("Enter your Father\'s name : "),
        class: prompt("Enter your Class : "),
        rollNo: prompt("Enter your Roll no. : ")
      };
      break;
    case 3:
      return
    default:
      console.log("\n\t\t...Enter a Valid Choice...");
  }
  }while(true);
}
start();
