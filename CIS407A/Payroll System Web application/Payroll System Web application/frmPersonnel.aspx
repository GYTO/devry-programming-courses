﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="frmPersonnel.aspx.cs" Inherits="frmPersonnel" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Add New Employee</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.2/css/bootstrap.min.css" integrity="sha384-Smlep5jCw/wG7hdkwQ/Z5nLIefveQRIY9nfy6xoR1uRYBtpZgI6339F5dgvm/e9B" crossorigin="anonymous" />
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.2/js/bootstrap.min.js" integrity="sha384-o+RDsa0aLu++PJvFqy8fFScvbHFLtbvScb8AjopnFD+iEQ7wo/CG0xlczd+2O/em" crossorigin="anonymous"></script>
</head>
<body>
    <div class="container">
        <div class="row">
            <div class="offset-2 col-8">
                <div class="card p-4 mt-3">
                    <form id="form1" runat="server">
                        <div class="d-flex justify-content-center">
                            <asp:ImageButton ID="Image1" runat="server" ImageAlign="Middle" ImageUrl="~/Images/CIS407A_iLab_ACITLogo.jpg" CssClass="img-fluid" PostBackUrl="~/frmMain.aspx" />
                        </div>
                        <div class="d-flex justify-content-center">
                            <asp:Panel ID="Panel1" runat="server" Height="250px" HorizontalAlign="Left" Width="300px">
                                <div class="form-group row mb-1">
                                    <asp:Label ID="firstName" runat="server" Text="First Name:" CssClass="col-sm-4 col-form-label col-form-label-sm"></asp:Label>
                                    <div class="col-sm-8">
                                        <asp:TextBox ID="txtFirstName" runat="server" CssClass="form-control form-control-sm"></asp:TextBox>
                                    </div>
                                </div>
                                <div class="form-group row mb-1">
                                    <asp:Label ID="lastName" runat="server" Text="Last Name:" CssClass="col-sm-4 col-form-label col-form-label-sm"></asp:Label>
                                    <div class="col-sm-8">
                                        <asp:TextBox ID="txtLastName" runat="server" CssClass="form-control form-control-sm"></asp:TextBox>
                                    </div>
                                </div>
                                <div class="form-group row mb-1">
                                    <asp:Label ID="payRate" runat="server" Text="Pay Rate:" CssClass="col-sm-4 col-form-label col-form-label-sm"></asp:Label>
                                    <div class="col-sm-8">
                                        <asp:TextBox ID="txtPayRate" runat="server" CssClass="form-control form-control-sm"></asp:TextBox>
                                     </div>
                                </div>
                                <div class="form-group row mb-1">
                                    <asp:Label ID="startDate" runat="server" Text="Start Date:" CssClass="col-sm-4 col-form-label col-form-label-sm"></asp:Label>
                                    <div class="col-sm-8">
                                        <asp:TextBox ID="txtStartDate" runat="server" CssClass="form-control form-control-sm"></asp:TextBox>
                                    </div>
                                </div>
                                <div class="form-group row mb-1">
                                    <asp:Label ID="endDate" runat="server" Text="End Date:" CssClass="col-sm-4 col-form-label col-form-label-sm"></asp:Label>
                                    <div class="col-sm-8">
                                        <asp:TextBox ID="txtEndDate" runat="server" CssClass="form-control form-control-sm"></asp:TextBox>
                                    </div>
                                </div>
                                <div class="d-flex mt-3">
                                    <asp:Button ID="btnSubmit" runat="server" Text="Submit" CssClass="btn btn-primary btn-block mr-1" PostBackUrl="~/frmPersonnelVerified.aspx" />
                                    <asp:Button ID="btnCancel" runat="server" Text="Cancel" CssClass="btn btn-danger btn-block mt-0 ml-1" PostBackUrl="~/frmMain.aspx" />
                                </div>
                            </asp:Panel>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</body>
</html>
