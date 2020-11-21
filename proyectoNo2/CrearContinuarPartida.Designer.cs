namespace proyectoNo2
{
    partial class CrearContinuarPartida
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.Btn_crearpartida = new System.Windows.Forms.Button();
            this.Btn_continuarpartida = new System.Windows.Forms.Button();
            this.Btn_top10 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ControlText;
            this.label1.Location = new System.Drawing.Point(248, 104);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(139, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Crear Partida";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(248, 167);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(179, 25);
            this.label2.TabIndex = 1;
            this.label2.Text = "Continuar Partida";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(248, 227);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(79, 25);
            this.label3.TabIndex = 2;
            this.label3.Text = "Top 10";
            // 
            // Btn_crearpartida
            // 
            this.Btn_crearpartida.BackColor = System.Drawing.Color.Coral;
            this.Btn_crearpartida.Location = new System.Drawing.Point(175, 100);
            this.Btn_crearpartida.Name = "Btn_crearpartida";
            this.Btn_crearpartida.Size = new System.Drawing.Size(48, 38);
            this.Btn_crearpartida.TabIndex = 3;
            this.Btn_crearpartida.UseVisualStyleBackColor = false;
            this.Btn_crearpartida.Click += new System.EventHandler(this.Btn_crearpartida_Click);
            // 
            // Btn_continuarpartida
            // 
            this.Btn_continuarpartida.BackColor = System.Drawing.Color.LightSeaGreen;
            this.Btn_continuarpartida.Location = new System.Drawing.Point(175, 162);
            this.Btn_continuarpartida.Name = "Btn_continuarpartida";
            this.Btn_continuarpartida.Size = new System.Drawing.Size(48, 38);
            this.Btn_continuarpartida.TabIndex = 4;
            this.Btn_continuarpartida.UseVisualStyleBackColor = false;
            // 
            // Btn_top10
            // 
            this.Btn_top10.BackColor = System.Drawing.Color.Crimson;
            this.Btn_top10.Location = new System.Drawing.Point(175, 222);
            this.Btn_top10.Name = "Btn_top10";
            this.Btn_top10.Size = new System.Drawing.Size(48, 38);
            this.Btn_top10.TabIndex = 5;
            this.Btn_top10.UseVisualStyleBackColor = false;
            this.Btn_top10.Click += new System.EventHandler(this.Btn_top10_Click);
            // 
            // CrearContinuarPartida
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(613, 354);
            this.Controls.Add(this.Btn_top10);
            this.Controls.Add(this.Btn_continuarpartida);
            this.Controls.Add(this.Btn_crearpartida);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "CrearContinuarPartida";
            this.Text = "CrearContinuarPartida";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.CrearContinuarPartida_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Btn_crearpartida;
        private System.Windows.Forms.Button Btn_continuarpartida;
        private System.Windows.Forms.Button Btn_top10;
    }
}