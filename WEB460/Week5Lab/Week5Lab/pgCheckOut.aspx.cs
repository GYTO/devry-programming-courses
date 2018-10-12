﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class pgCheckOut : System.Web.UI.Page
{
    // Create a class to Business layer
    clsBusinessLayer myBusinessLayer;

    protected void Page_Load(object sender, EventArgs e)
    {
        // let user know that he/she need to insert th ebilling information
        Master.UserFeedback.Text = "Please enter billing information.";
        Master.UserFeedback.CssClass = "alert alert-danger";

        // Create a path to APP DATA
        myBusinessLayer = new clsBusinessLayer(Server.MapPath("~/App_Data/"));

        // Bind Customer GridView
        BindCustomerGridView();

        // Bind XML GridView
        BindXMLGridView();
    }
    protected void RblCCType_SelectedIndexChanged(object sender, EventArgs e) {}
    protected void BtnSubmit_Click(object sender, EventArgs e) {}

    // On Click Find a Last Name in DB
    protected void BtnFindLastName_Click(object sender, EventArgs e)
    {
        // Connect to the dsAccount Object
        dsAccounts dsFindLastName = myBusinessLayer.FindCustomer(txtLastName.Text);

        // Find a DB in the files
        string tempPath = Server.MapPath("~/App_Data/Accounts.mdb");
        clsDataLayer dataLayerObj = new clsDataLayer(tempPath);

        // If the customer is exist then fill the records
        if (dsFindLastName.tblCustomers.Rows.Count > 0)
        {
            // Take a recods from the field and path trough the Text Inputs
            txtFirstName.Text = dsFindLastName.tblCustomers[0].FirstName;
            txtLastName.Text = dsFindLastName.tblCustomers[0].LastName;
            txtLine1.Text = dsFindLastName.tblCustomers[0].Address1;
            txtLine2.Text = dsFindLastName.tblCustomers[0].Address2;
            txtCity.Text = dsFindLastName.tblCustomers[0].City;
            txtState.Text = dsFindLastName.tblCustomers[0].State;
            txtPhone.Text = dsFindLastName.tblCustomers[0].PhoneNumber;
            customerID.Text = dsFindLastName.tblCustomers[0].CustomerID.ToString();

            Master.UserFeedback.Text = "Record Found";
            Master.UserFeedback.CssClass = "alert alert-success";
        }
        else
        {
            // Recocd Fails if user was not found
            Master.UserFeedback.Text = "No records were Found!";
            Master.UserFeedback.CssClass = "alert alert-danger";
        }
    }

    // On Click Update User Inforation
    protected void BtnUpdateCustomer_Click(object sender, EventArgs e)
    {
        // Find a DB in the files
        string tempPath = Server.MapPath("~/App_Data/Accounts.mdb");
        clsDataLayer myDataLayer = new clsDataLayer(tempPath);

        // Update customer information
        string results = myBusinessLayer.UpdateCustomer(
            txtFirstName.Text,
            txtLastName.Text,
            txtLine1.Text,
            txtLine2.Text,
            txtCity.Text,
            txtState.Text,
            txtPhone.Text,
            Convert.ToInt32(customerID.Text));

        // update the form
        updateForm(results);
    }

    // On Click Create new User in DB
    protected void BtnAddCustomer_Click(object sender, EventArgs e)
    {
        // Find a DB in the files
        string tempPath = Server.MapPath("~/App_Data/Accounts.mdb");
        clsDataLayer myDataLayer = new clsDataLayer(tempPath);

        // Add User information
        string results = myBusinessLayer.InsertCustomer(
            txtFirstName.Text,
            txtLastName.Text,
            txtLine1.Text,
            txtLine2.Text,
            txtCity.Text,
            txtState.Text,
            txtPhone.Text);

        // Update Form
        updateForm(results);
    }

    // Private Clear Input Form
    private void ClearInputs(ControlCollection ctrls)
    {
        foreach (Control ctrl in ctrls)
        {
            if (ctrl is TextBox)
                ((TextBox)ctrl).Text = string.Empty;
            else if (ctrl is DropDownList)
                ((DropDownList)ctrl).ClearSelection();
            else if (ctrl is RadioButton)
                ((RadioButton)ctrl).Checked = false;
            else if (ctrl is RadioButtonList)
                ((RadioButtonList)ctrl).ClearSelection();
            else
                ClearInputs(ctrl.Controls);
        }
    }

    private dsAccounts BindCustomerGridView()
    {
        // Find a DB in the files
        string tempPath = Server.MapPath("~/App_Data/Accounts.mdb");
        clsDataLayer myDataLayer = new clsDataLayer(tempPath);

        // Call the class and bind it to the customer listing
        dsAccounts customerListing = myBusinessLayer.SelectAllCustomers();

        // Bind to the GridView
        gvCustomerList.DataSource = customerListing.tblCustomers;

        // Bind the data
        gvCustomerList.DataBind();
        Cache.Insert("CustomerDataSet", customerListing);

        return customerListing;
    }
    
    // Clear Button Form
    public void BtnClearForm_Click(object sender, EventArgs e)
    {
        ClearInputs(Page.Controls);
        customerID.Text = null;
    }


    public void BtnUpdateXML_Click(object sender, EventArgs e)
    {
        // Bind data from a click
        gvXML.DataSource = myBusinessLayer.WriteCustomerXMLFile(Cache);
        gvXML.DataBind();
    }

    public void BindXMLGridView()
    {
        // Bind to the GridView
        gvXML.DataSource = myBusinessLayer.GetCustomerXMLFile();
        gvXML.DataBind();

        // Let user know that it was bind
        Master.UserFeedback.Text = "Customer was Updated to the XML File";
        Master.UserFeedback.CssClass = "alert alert-success";
    }

    private void updateForm(string results)
    {
        // clear all inputs
        ClearInputs(Page.Controls);

        // comment the result
        Master.UserFeedback.Text = results;
        Master.UserFeedback.CssClass = "alert alert-warning";

        // bind to the gridview
        BindCustomerGridView();
    }

    /*
     * Creating public TextBoxes to return the value from a form
     * FirstName - user first name 
     * LastName - user last name
     * AddressLine1 - user first address
     * AddressLine2 - user second address
     * City - user city
     * State - user state
     * Phone - user phone
     * CCNumber - user card number
     * CCType - user type of the card, has values (Visa, Master Card, Discovery)
     */

    public TextBox FirstName { get { return txtFirstName; } }
    public TextBox LastName { get { return txtLastName; } }
    public TextBox AddressLine1 { get { return txtLine1; } }
    public TextBox AddressLine2 { get { return txtLine2; } }
    public TextBox City { get { return txtCity; } }
    public TextBox State { get { return txtState; } }
    public TextBox Phone { get { return txtPhone; } }
    public TextBox CCNumber { get { return txtCCNumber; } }
    public RadioButtonList CCType { get { return rblCCType; } }

}