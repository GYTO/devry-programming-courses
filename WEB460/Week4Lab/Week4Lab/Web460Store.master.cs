﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Web460Store : System.Web.UI.MasterPage
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
        {
            lblGUID.Text = System.Guid.NewGuid().ToString();
        }
    }

    public Label UserFeedback
    {
        get { return lblUserFeedBack; }
        set { lblUserFeedBack = value; }
    }
}
