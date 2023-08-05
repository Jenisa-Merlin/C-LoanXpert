C LoanXpert
A feature-rich project that employs files, functions, structures, and arrays to manage cash loans and deposits. It incorporates admin and customer logins with distinct access levels, enabling smooth operation of various loan schemes.

                                                              
              FINANCE MANAGEMENT SYSTEM

        In this mini project we have built a code using C language to manage the needs of a finance.  We have used various aspects of C language like files, functions, structures and arrays. This finance provides cash loan and cash deposit for the customers with various schemes.
     In our project there are two logins admin and customer.

ADMIN:
       For admin to login, they should enter their username (admin) and password (psg3908). 
         After we logged into admin, we have options like
o	new customer
o	existing customer
o	search
o	delete
o	exit
NEWCUSTOMER:
                       It creates separate file for every customer in the name of the user ID. We (the admin) have to provide the user ID and password for each customer to access their account.
                      The user ID and password provided by the admin to all the customers is stored in a file named signup which can be accessed if needed.
                       And then we (the admin) need to enter the details of the customer which will be stored in that (user ID of the customer) file. That file contains the details of that particular customer.
EXISTING CUSTOMER:
                          We have to enter the user ID and password of that customer to log in to their account.
                 After entering the user ID and password of the customer it will verify it. 
                Once the login is success, we have two options:
	Loan
	Deposit
                  LOAN:
                               In loan we have two options:
                                                 1) New loan 
                                                 2) Existing loan
                              NEWLOAN:
                                    For each new loan it generates a loan ID and creates a separate file under the name of loan ID.
                                   The customer and admin should aware of the loan ID for further access.
                             EXISTING LOAN:
                                                         We have to enter the loan ID to access the details of a particular loan. Once the login is successful, we have 2 choices:
                              i) To pay the loan amount 
                              ii) To pay the loan interest.
                               If the customer paid the loan amount, then the interest amount also calculated automatically.
                               The due date of the particular loan of the customer is also automatically calculated using a function call.
                 DEPOSIT:
                               For each customer a deposit ID is generated and the file also created in that particular deposit ID.
                                And then the deposit schemes available in our finance is displayed.
                               Accordingly, the customer can deposit which will be stored in that file and the amount available after the completion of deposit scheme along with expiry date is also stored in that file and displayed.
          SEARCH:
                       It has three options: 
	We can search a customer using their user ID which prints the details of the customer
	We can search a loan detail of a customer using the loan ID of the particular customer and it prints the details of that particular loan.
	 We can search a deposit detail of a customer using the deposit ID of the particular customer and it prints the details of that particular deposit.
It will continue asking till the need of searching ends...!

DELETE:
                                     It has three options:
     
	We can delete a customer by entering the user ID of that customer (which is the file name).
	We can delete a loan by entering the loan ID of that particular loan. 
	We can delete a deposit by entering the deposit ID of that particular deposit.
The deleting option will display till the deletion part ends by the admin.

CUSTOMER:
            For customer, first it is asked to enter the user ID and password which will be verified by login function.
       Once the login is success, it displays 3 option :
a)	To view their personal details.
b)	To view their loan details.
c)	To view their deposit details.
        According to their selection, the file is opened and displays their details.
	By entering the user ID, he/she can view their personal details.
	By entering the loan ID, he/she can view the details of their particular loan.
	By entering the deposit ID, he/she can view the details of their particular deposit.
It continues asking till the customer exits.


