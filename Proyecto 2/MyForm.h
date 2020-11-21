#pragma once
#include "Bodega.h"
#include "Producto.h"

namespace Proyecto2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Timer^  timer1;

	private: System::Windows::Forms::CheckBox^  Id_Bahia_Nueva_1;
	private: System::Windows::Forms::CheckBox^  Id_Bahia_Nueva_2;
	private: System::Windows::Forms::CheckBox^  Id_Bahia_Nueva_3;
	private: System::Windows::Forms::TextBox^  Bahia_Encontrada;
	private: System::Windows::Forms::TextBox^  Fila_Bahia_Buscar;
	private: System::Windows::Forms::TextBox^  Columna_Bahia_Buscar;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  Buscar;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	public:
		Bodega^ BodegaPricipal = gcnew Bodega();
	private: System::Windows::Forms::Button^  Eliminar_Bahia;
	private: System::Windows::Forms::TextBox^  Productos_Encontrados;
	public:

	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  Nombre_Saco;
	private: System::Windows::Forms::TextBox^  Cantidad_Sacar_Unidades;
	private: System::Windows::Forms::CheckBox^  ID_3_Producto_Buscando;
	private: System::Windows::Forms::CheckBox^  ID_2_Producto_Buscando;
	private: System::Windows::Forms::CheckBox^  ID_1_Producto_Buscando;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::TextBox^  Columna_Bahia_P;
	private: System::Windows::Forms::TextBox^  Fila_Bahia_P;
	private: System::Windows::Forms::Button^  Eliminar_Producto;
	private: System::Windows::Forms::TextBox^  BodegaInfo;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  Buscar_Producto;



			 Bahia^ Almacenar_Info;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Peso_Maximo_Nueva_Bahia;
	protected:

	protected:
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::Windows::Forms::TextBox^  Ubicacion_Fila;
	private: System::Windows::Forms::TextBox^  Ubicacion_Columna;
	private: System::Windows::Forms::TextBox^  Peso_Producto;





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  Id_Producto;
	private: System::Windows::Forms::TextBox^  Fila_Producto;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  Columna_Producto;
	private: System::Windows::Forms::TextBox^  Cantidad_Productos;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  Agregar;
	private: System::Windows::Forms::Label^  label11;

	private: System::Windows::Forms::TextBox^  Nombre_Ingreso;
	private: System::Windows::Forms::Label^  label13;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Peso_Maximo_Nueva_Bahia = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->Ubicacion_Fila = (gcnew System::Windows::Forms::TextBox());
			this->Ubicacion_Columna = (gcnew System::Windows::Forms::TextBox());
			this->Peso_Producto = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Id_Producto = (gcnew System::Windows::Forms::TextBox());
			this->Fila_Producto = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Columna_Producto = (gcnew System::Windows::Forms::TextBox());
			this->Cantidad_Productos = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Agregar = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->Nombre_Ingreso = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Id_Bahia_Nueva_1 = (gcnew System::Windows::Forms::CheckBox());
			this->Id_Bahia_Nueva_2 = (gcnew System::Windows::Forms::CheckBox());
			this->Id_Bahia_Nueva_3 = (gcnew System::Windows::Forms::CheckBox());
			this->Bahia_Encontrada = (gcnew System::Windows::Forms::TextBox());
			this->Fila_Bahia_Buscar = (gcnew System::Windows::Forms::TextBox());
			this->Columna_Bahia_Buscar = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->Buscar = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->Eliminar_Bahia = (gcnew System::Windows::Forms::Button());
			this->Productos_Encontrados = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->Nombre_Saco = (gcnew System::Windows::Forms::TextBox());
			this->Cantidad_Sacar_Unidades = (gcnew System::Windows::Forms::TextBox());
			this->ID_3_Producto_Buscando = (gcnew System::Windows::Forms::CheckBox());
			this->ID_2_Producto_Buscando = (gcnew System::Windows::Forms::CheckBox());
			this->ID_1_Producto_Buscando = (gcnew System::Windows::Forms::CheckBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->Columna_Bahia_P = (gcnew System::Windows::Forms::TextBox());
			this->Fila_Bahia_P = (gcnew System::Windows::Forms::TextBox());
			this->Eliminar_Producto = (gcnew System::Windows::Forms::Button());
			this->BodegaInfo = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Buscar_Producto = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Peso_Maximo_Nueva_Bahia
			// 
			this->Peso_Maximo_Nueva_Bahia->Location = System::Drawing::Point(37, 97);
			this->Peso_Maximo_Nueva_Bahia->Name = L"Peso_Maximo_Nueva_Bahia";
			this->Peso_Maximo_Nueva_Bahia->Size = System::Drawing::Size(140, 20);
			this->Peso_Maximo_Nueva_Bahia->TabIndex = 0;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Agregar Bahia", L"Agregar Productos", L"Agregar Bahias y Productos" });
			this->comboBox1->Location = System::Drawing::Point(37, 45);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(162, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// Ubicacion_Fila
			// 
			this->Ubicacion_Fila->Location = System::Drawing::Point(37, 234);
			this->Ubicacion_Fila->Name = L"Ubicacion_Fila";
			this->Ubicacion_Fila->Size = System::Drawing::Size(140, 20);
			this->Ubicacion_Fila->TabIndex = 3;
			// 
			// Ubicacion_Columna
			// 
			this->Ubicacion_Columna->Location = System::Drawing::Point(37, 278);
			this->Ubicacion_Columna->Name = L"Ubicacion_Columna";
			this->Ubicacion_Columna->Size = System::Drawing::Size(140, 20);
			this->Ubicacion_Columna->TabIndex = 4;
			// 
			// Peso_Producto
			// 
			this->Peso_Producto->Location = System::Drawing::Point(245, 96);
			this->Peso_Producto->Name = L"Peso_Producto";
			this->Peso_Producto->Size = System::Drawing::Size(140, 20);
			this->Peso_Producto->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(37, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Peso  maximo para la bahia";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Tipo de Producto";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 218);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Fila en donde ubicar";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(37, 262);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Columna a ubicar";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(245, 80);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(130, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Peso unitario del producto";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// Id_Producto
			// 
			this->Id_Producto->Location = System::Drawing::Point(245, 141);
			this->Id_Producto->Name = L"Id_Producto";
			this->Id_Producto->Size = System::Drawing::Size(140, 20);
			this->Id_Producto->TabIndex = 11;
			// 
			// Fila_Producto
			// 
			this->Fila_Producto->Location = System::Drawing::Point(245, 185);
			this->Fila_Producto->Name = L"Fila_Producto";
			this->Fila_Producto->Size = System::Drawing::Size(140, 20);
			this->Fila_Producto->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(245, 125);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Id del producto";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(245, 169);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(112, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Fila en la cual ingresar";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(245, 217);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(137, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Columna en la cual ingresar";
			// 
			// Columna_Producto
			// 
			this->Columna_Producto->Location = System::Drawing::Point(245, 233);
			this->Columna_Producto->Name = L"Columna_Producto";
			this->Columna_Producto->Size = System::Drawing::Size(140, 20);
			this->Columna_Producto->TabIndex = 16;
			// 
			// Cantidad_Productos
			// 
			this->Cantidad_Productos->Location = System::Drawing::Point(245, 325);
			this->Cantidad_Productos->Name = L"Cantidad_Productos";
			this->Cantidad_Productos->Size = System::Drawing::Size(140, 20);
			this->Cantidad_Productos->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(245, 309);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(114, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Cantidad de productos";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(34, 29);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Opcion a trabajar";
			// 
			// Agregar
			// 
			this->Agregar->Location = System::Drawing::Point(37, 322);
			this->Agregar->Name = L"Agregar";
			this->Agregar->Size = System::Drawing::Size(140, 23);
			this->Agregar->TabIndex = 20;
			this->Agregar->Text = L"Agregar";
			this->Agregar->UseVisualStyleBackColor = true;
			this->Agregar->Click += gcnew System::EventHandler(this, &MyForm::Agregar_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(448, 80);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(138, 52);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Id\'s de Productos\r\n1. Articulos de oficina\r\n2. Ropa\r\n3. Articulos de construccion"
				L"\r\n";
			// 
			// Nombre_Ingreso
			// 
			this->Nombre_Ingreso->Location = System::Drawing::Point(245, 278);
			this->Nombre_Ingreso->Name = L"Nombre_Ingreso";
			this->Nombre_Ingreso->Size = System::Drawing::Size(140, 20);
			this->Nombre_Ingreso->TabIndex = 24;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(245, 262);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(110, 13);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Nombre del empleado";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 60000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// Id_Bahia_Nueva_1
			// 
			this->Id_Bahia_Nueva_1->AutoSize = true;
			this->Id_Bahia_Nueva_1->Location = System::Drawing::Point(34, 142);
			this->Id_Bahia_Nueva_1->Name = L"Id_Bahia_Nueva_1";
			this->Id_Bahia_Nueva_1->Size = System::Drawing::Size(115, 17);
			this->Id_Bahia_Nueva_1->TabIndex = 26;
			this->Id_Bahia_Nueva_1->Text = L"Articulos de oficina";
			this->Id_Bahia_Nueva_1->UseVisualStyleBackColor = true;
			// 
			// Id_Bahia_Nueva_2
			// 
			this->Id_Bahia_Nueva_2->AutoSize = true;
			this->Id_Bahia_Nueva_2->Location = System::Drawing::Point(34, 165);
			this->Id_Bahia_Nueva_2->Name = L"Id_Bahia_Nueva_2";
			this->Id_Bahia_Nueva_2->Size = System::Drawing::Size(52, 17);
			this->Id_Bahia_Nueva_2->TabIndex = 27;
			this->Id_Bahia_Nueva_2->Text = L"Ropa";
			this->Id_Bahia_Nueva_2->UseVisualStyleBackColor = true;
			// 
			// Id_Bahia_Nueva_3
			// 
			this->Id_Bahia_Nueva_3->AutoSize = true;
			this->Id_Bahia_Nueva_3->Location = System::Drawing::Point(34, 188);
			this->Id_Bahia_Nueva_3->Name = L"Id_Bahia_Nueva_3";
			this->Id_Bahia_Nueva_3->Size = System::Drawing::Size(153, 17);
			this->Id_Bahia_Nueva_3->TabIndex = 28;
			this->Id_Bahia_Nueva_3->Text = L"Materiales de construcción";
			this->Id_Bahia_Nueva_3->UseVisualStyleBackColor = true;
			// 
			// Bahia_Encontrada
			// 
			this->Bahia_Encontrada->Location = System::Drawing::Point(617, 96);
			this->Bahia_Encontrada->Multiline = true;
			this->Bahia_Encontrada->Name = L"Bahia_Encontrada";
			this->Bahia_Encontrada->Size = System::Drawing::Size(140, 192);
			this->Bahia_Encontrada->TabIndex = 29;
			// 
			// Fila_Bahia_Buscar
			// 
			this->Fila_Bahia_Buscar->Location = System::Drawing::Point(979, 112);
			this->Fila_Bahia_Buscar->Name = L"Fila_Bahia_Buscar";
			this->Fila_Bahia_Buscar->Size = System::Drawing::Size(140, 20);
			this->Fila_Bahia_Buscar->TabIndex = 30;
			// 
			// Columna_Bahia_Buscar
			// 
			this->Columna_Bahia_Buscar->Location = System::Drawing::Point(979, 155);
			this->Columna_Bahia_Buscar->Name = L"Columna_Bahia_Buscar";
			this->Columna_Bahia_Buscar->Size = System::Drawing::Size(140, 20);
			this->Columna_Bahia_Buscar->TabIndex = 31;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(621, 80);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(91, 13);
			this->label12->TabIndex = 32;
			this->label12->Text = L"Bahia encontrada";
			// 
			// Buscar
			// 
			this->Buscar->Location = System::Drawing::Point(979, 185);
			this->Buscar->Name = L"Buscar";
			this->Buscar->Size = System::Drawing::Size(140, 23);
			this->Buscar->TabIndex = 33;
			this->Buscar->Text = L"Buscar bahia por posicion";
			this->Buscar->UseVisualStyleBackColor = true;
			this->Buscar->Click += gcnew System::EventHandler(this, &MyForm::Buscar_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(976, 96);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(96, 13);
			this->label14->TabIndex = 34;
			this->label14->Text = L"Fila bahia a buscar";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(976, 139);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(121, 13);
			this->label15->TabIndex = 35;
			this->label15->Text = L"Columna bahia a buscar";
			// 
			// Eliminar_Bahia
			// 
			this->Eliminar_Bahia->Location = System::Drawing::Point(979, 214);
			this->Eliminar_Bahia->Name = L"Eliminar_Bahia";
			this->Eliminar_Bahia->Size = System::Drawing::Size(140, 23);
			this->Eliminar_Bahia->TabIndex = 36;
			this->Eliminar_Bahia->Text = L"Eliminar Bahia";
			this->Eliminar_Bahia->UseVisualStyleBackColor = true;
			this->Eliminar_Bahia->Click += gcnew System::EventHandler(this, &MyForm::Eliminar_Bahia_Click);
			// 
			// Productos_Encontrados
			// 
			this->Productos_Encontrados->Location = System::Drawing::Point(792, 96);
			this->Productos_Encontrados->Multiline = true;
			this->Productos_Encontrados->Name = L"Productos_Encontrados";
			this->Productos_Encontrados->Size = System::Drawing::Size(140, 192);
			this->Productos_Encontrados->TabIndex = 37;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(789, 80);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(107, 13);
			this->label16->TabIndex = 38;
			this->label16->Text = L"Producto encontrada";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(1343, 72);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(121, 13);
			this->label17->TabIndex = 42;
			this->label17->Text = L"Nombre del responsable";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(1343, 29);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(110, 13);
			this->label18->TabIndex = 41;
			this->label18->Text = L"Cantidad de unidades";
			// 
			// Nombre_Saco
			// 
			this->Nombre_Saco->Location = System::Drawing::Point(1346, 88);
			this->Nombre_Saco->Name = L"Nombre_Saco";
			this->Nombre_Saco->Size = System::Drawing::Size(140, 20);
			this->Nombre_Saco->TabIndex = 40;
			// 
			// Cantidad_Sacar_Unidades
			// 
			this->Cantidad_Sacar_Unidades->Location = System::Drawing::Point(1346, 45);
			this->Cantidad_Sacar_Unidades->Name = L"Cantidad_Sacar_Unidades";
			this->Cantidad_Sacar_Unidades->Size = System::Drawing::Size(140, 20);
			this->Cantidad_Sacar_Unidades->TabIndex = 39;
			// 
			// ID_3_Producto_Buscando
			// 
			this->ID_3_Producto_Buscando->AutoSize = true;
			this->ID_3_Producto_Buscando->Location = System::Drawing::Point(1346, 181);
			this->ID_3_Producto_Buscando->Name = L"ID_3_Producto_Buscando";
			this->ID_3_Producto_Buscando->Size = System::Drawing::Size(153, 17);
			this->ID_3_Producto_Buscando->TabIndex = 46;
			this->ID_3_Producto_Buscando->Text = L"Materiales de construcción";
			this->ID_3_Producto_Buscando->UseVisualStyleBackColor = true;
			this->ID_3_Producto_Buscando->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ID_3_Producto_Buscando_CheckedChanged);
			// 
			// ID_2_Producto_Buscando
			// 
			this->ID_2_Producto_Buscando->AutoSize = true;
			this->ID_2_Producto_Buscando->Location = System::Drawing::Point(1346, 158);
			this->ID_2_Producto_Buscando->Name = L"ID_2_Producto_Buscando";
			this->ID_2_Producto_Buscando->Size = System::Drawing::Size(52, 17);
			this->ID_2_Producto_Buscando->TabIndex = 45;
			this->ID_2_Producto_Buscando->Text = L"Ropa";
			this->ID_2_Producto_Buscando->UseVisualStyleBackColor = true;
			this->ID_2_Producto_Buscando->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ID_2_Producto_Buscando_CheckedChanged);
			// 
			// ID_1_Producto_Buscando
			// 
			this->ID_1_Producto_Buscando->AutoSize = true;
			this->ID_1_Producto_Buscando->Location = System::Drawing::Point(1346, 135);
			this->ID_1_Producto_Buscando->Name = L"ID_1_Producto_Buscando";
			this->ID_1_Producto_Buscando->Size = System::Drawing::Size(115, 17);
			this->ID_1_Producto_Buscando->TabIndex = 44;
			this->ID_1_Producto_Buscando->Text = L"Articulos de oficina";
			this->ID_1_Producto_Buscando->UseVisualStyleBackColor = true;
			this->ID_1_Producto_Buscando->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ID_1_Producto_Buscando_CheckedChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(1346, 119);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(89, 13);
			this->label19->TabIndex = 43;
			this->label19->Text = L"Tipo de Producto";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(1346, 254);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(89, 13);
			this->label20->TabIndex = 50;
			this->label20->Text = L"Columna a ubicar";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(1346, 210);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(103, 13);
			this->label21->TabIndex = 49;
			this->label21->Text = L"Fila en donde ubicar";
			// 
			// Columna_Bahia_P
			// 
			this->Columna_Bahia_P->Location = System::Drawing::Point(1346, 270);
			this->Columna_Bahia_P->Name = L"Columna_Bahia_P";
			this->Columna_Bahia_P->Size = System::Drawing::Size(140, 20);
			this->Columna_Bahia_P->TabIndex = 48;
			// 
			// Fila_Bahia_P
			// 
			this->Fila_Bahia_P->Location = System::Drawing::Point(1346, 226);
			this->Fila_Bahia_P->Name = L"Fila_Bahia_P";
			this->Fila_Bahia_P->Size = System::Drawing::Size(140, 20);
			this->Fila_Bahia_P->TabIndex = 47;
			// 
			// Eliminar_Producto
			// 
			this->Eliminar_Producto->Location = System::Drawing::Point(1173, 309);
			this->Eliminar_Producto->Name = L"Eliminar_Producto";
			this->Eliminar_Producto->Size = System::Drawing::Size(140, 23);
			this->Eliminar_Producto->TabIndex = 51;
			this->Eliminar_Producto->Text = L"Eliminar Producto";
			this->Eliminar_Producto->UseVisualStyleBackColor = true;
			this->Eliminar_Producto->Click += gcnew System::EventHandler(this, &MyForm::Eliminar_Producto_Click);
			// 
			// BodegaInfo
			// 
			this->BodegaInfo->Location = System::Drawing::Point(451, 158);
			this->BodegaInfo->Multiline = true;
			this->BodegaInfo->Name = L"BodegaInfo";
			this->BodegaInfo->Size = System::Drawing::Size(140, 130);
			this->BodegaInfo->TabIndex = 52;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(1170, 80);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(107, 13);
			this->label22->TabIndex = 54;
			this->label22->Text = L"Producto encontrada";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1173, 96);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(140, 192);
			this->textBox1->TabIndex = 53;
			// 
			// Buscar_Producto
			// 
			this->Buscar_Producto->Location = System::Drawing::Point(1346, 309);
			this->Buscar_Producto->Name = L"Buscar_Producto";
			this->Buscar_Producto->Size = System::Drawing::Size(140, 23);
			this->Buscar_Producto->TabIndex = 55;
			this->Buscar_Producto->Text = L"Buscar Producto";
			this->Buscar_Producto->UseVisualStyleBackColor = true;
			this->Buscar_Producto->Click += gcnew System::EventHandler(this, &MyForm::Buscar_Producto_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1581, 367);
			this->Controls->Add(this->Buscar_Producto);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->BodegaInfo);
			this->Controls->Add(this->Eliminar_Producto);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->Columna_Bahia_P);
			this->Controls->Add(this->Fila_Bahia_P);
			this->Controls->Add(this->ID_3_Producto_Buscando);
			this->Controls->Add(this->ID_2_Producto_Buscando);
			this->Controls->Add(this->ID_1_Producto_Buscando);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->Nombre_Saco);
			this->Controls->Add(this->Cantidad_Sacar_Unidades);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->Productos_Encontrados);
			this->Controls->Add(this->Eliminar_Bahia);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->Buscar);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->Columna_Bahia_Buscar);
			this->Controls->Add(this->Fila_Bahia_Buscar);
			this->Controls->Add(this->Bahia_Encontrada);
			this->Controls->Add(this->Id_Bahia_Nueva_3);
			this->Controls->Add(this->Id_Bahia_Nueva_2);
			this->Controls->Add(this->Id_Bahia_Nueva_1);
			this->Controls->Add(this->Nombre_Ingreso);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->Agregar);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->Cantidad_Productos);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Columna_Producto);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->Fila_Producto);
			this->Controls->Add(this->Id_Producto);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Peso_Producto);
			this->Controls->Add(this->Ubicacion_Columna);
			this->Controls->Add(this->Ubicacion_Fila);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->Peso_Maximo_Nueva_Bahia);
			this->Name = L"MyForm";
			this->Text = L"Administracion de bodegas";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox1->Text == "Agregar Productos") {
			// estructuras para bahias
			Peso_Maximo_Nueva_Bahia->Visible = false;
			Id_Bahia_Nueva_1->Visible = false;
			Id_Bahia_Nueva_2->Visible = false;
			Id_Bahia_Nueva_3->Visible = false;
			Ubicacion_Fila->Visible = false;
			Ubicacion_Columna->Visible = false;
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			//estructuras para productosa
			label5->Visible = true;
			label6->Visible = true;
			label7->Visible = true;
			label8->Visible = true;
			label9->Visible = true;
			label13->Visible = true;
			Peso_Producto->Visible = true;
			Id_Producto->Visible = true;
			Fila_Producto->Visible = true;
			Columna_Producto->Visible = true;
			Nombre_Ingreso->Visible = true;
			Cantidad_Productos->Visible = true;
		}
		else if (comboBox1->Text == "Agregar Bahia") {
			Peso_Maximo_Nueva_Bahia->Visible = true;
			Id_Bahia_Nueva_1->Visible = true;
			Id_Bahia_Nueva_2->Visible = true;
			Id_Bahia_Nueva_3->Visible = true;
			Ubicacion_Fila->Visible = true;
			Ubicacion_Columna->Visible = true;
			label1->Visible = true;
			label2->Visible = true;
			label3->Visible = true;
			label4->Visible = true;
			//estructuras para productosa
			label5->Visible = false;
			label6->Visible = false;
			label7->Visible = false;
			label8->Visible = false;
			label9->Visible = false;
			label13->Visible = false;
			Peso_Producto->Visible = false;
			Id_Producto->Visible = false;
			Fila_Producto->Visible = false;
			Columna_Producto->Visible = false;
			Nombre_Ingreso->Visible = false;
			Cantidad_Productos->Visible = false;

		}
		else if (comboBox1->Text == "Agregar Bahias y Productos") {
			Peso_Maximo_Nueva_Bahia->Visible = true;
			Id_Bahia_Nueva_1->Visible = true;
			Id_Bahia_Nueva_2->Visible = true;
			Id_Bahia_Nueva_3->Visible = true;
			Ubicacion_Fila->Visible = true;
			Ubicacion_Columna->Visible = true;
			label1->Visible = true;
			label2->Visible = true;
			label3->Visible = true;
			label4->Visible = true;
			//estructuras para productosa
			label5->Visible = true;
			label6->Visible = true;
			label7->Visible = true;
			label8->Visible = true;
			label9->Visible = true;
			label13->Visible = true;
			Peso_Producto->Visible = true;
			Id_Producto->Visible = true;
			Fila_Producto->Visible = true;
			Columna_Producto->Visible = true;
			Nombre_Ingreso->Visible = true;
			Cantidad_Productos->Visible = true;

		}
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Agregar_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			DateTime dia;
			if (comboBox1->Text == "Agregar Productos") {
				if (Cantidad_Productos->Text != "") {
					int cantidad_de_productos = Convert::ToInt16(Cantidad_Productos->Text);
					if (Fila_Producto->Text == "" || Columna_Producto->Text == "") {
						Bahia^ B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
						for (int i = 0; i < cantidad_de_productos; i++)
						{
							dia = DateTime::Now;
							Producto^ P1 = gcnew Producto(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text), Nombre_Ingreso->Text, Convert::ToString(dia));
							if (!B1->IngresarProducto(P1)) {
								B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
								if (B1 == nullptr) {
									MessageBox::Show("Se pudieron ingrsar " + i + " productos, faltaron " + (cantidad_de_productos - i) + "productos");
									break;
								}
								B1->IngresarProducto(P1);
							}
						}
					}
					else {
						Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Convert::ToChar(Fila_Producto->Text), Convert::ToInt16(Columna_Producto->Text));
						for (int i = 1; i <= cantidad_de_productos; i++)
						{
							dia = DateTime::Now;
							Producto^ P1 = gcnew Producto(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text), Nombre_Ingreso->Text, Convert::ToString(dia));
							if (!B1->IngresarProducto(P1)) {
								B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
								if (B1 == nullptr) {
									MessageBox::Show("Se pudieron ingrsar " + (i - 1) + " productos, faltaron " + (cantidad_de_productos - i + 1) + " productos");
									break;
								}
								B1->IngresarProducto(P1);
								Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Convert::ToChar(Fila_Producto->Text), Convert::ToInt16(Columna_Producto->Text));
							}
						}
					}
				}
				else {
					if (Fila_Producto->Text == "" || Columna_Producto->Text == "") {
						Bahia^ B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
						Producto^ P1 = gcnew Producto(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text), Nombre_Ingreso->Text, Convert::ToString(dia));
						if (!B1->IngresarProducto(P1)) {
							B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
							if (B1 == nullptr) {
								MessageBox::Show("No se pudieron ingrsar Por falta de Bahias de este tipo");
							}
							else {
								B1->IngresarProducto(P1);
							}
						}
						else if (B1 == nullptr) {
							MessageBox::Show("No se pudieron ingrsar Por falta de Bahias de este tipo");
						}
					}
					else {
						Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Convert::ToChar(Fila_Producto->Text), Convert::ToInt16(Columna_Producto->Text));
						Producto^ P1 = gcnew Producto(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text), Nombre_Ingreso->Text, Convert::ToString(dia));
						if (!B1->IngresarProducto(P1)) {
							B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
							if (B1 == nullptr) {
								MessageBox::Show("No se pudo ingrsar.\nBahias sin espacio para este articulo");
							}
							else {
								B1->IngresarProducto(P1);
							}
						}
					}
				}
			}
			else if (comboBox1->Text == "Agregar Bahia") {
				int CantidadMaximaDePeso = Convert::ToInt16(Peso_Maximo_Nueva_Bahia->Text);
				int ID_Bahia;
				if (Id_Bahia_Nueva_1->Checked && Id_Bahia_Nueva_2->Checked && Id_Bahia_Nueva_3->Checked) {
					ID_Bahia = 4;
				}
				else if (Id_Bahia_Nueva_1->Checked && Id_Bahia_Nueva_2->Checked) {
					ID_Bahia = 5;
				}
				else if (Id_Bahia_Nueva_2->Checked && Id_Bahia_Nueva_3->Checked) {
					ID_Bahia = 6;
				}
				else if (Id_Bahia_Nueva_1->Checked && Id_Bahia_Nueva_3->Checked) {
					ID_Bahia = 7;
				}
				else if (Id_Bahia_Nueva_1->Checked)
					ID_Bahia = 1;
				else if (Id_Bahia_Nueva_2->Checked)
					ID_Bahia = 2;
				else if (Id_Bahia_Nueva_3->Checked)
					ID_Bahia = 3;
				else {
					ID_Bahia = 4;
					MessageBox::Show("Ya que no ingreso ningun tipo la Bahia procedera a ser de tipo 4(todo tipo de producto)");
				}

				char Fila_bahia = Convert::ToChar(Ubicacion_Fila->Text);
				int Columna_Bahia = Convert::ToInt16(Ubicacion_Columna->Text);

				Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Fila_bahia, Columna_Bahia);
				if (B1 == nullptr) {
					BodegaPricipal->Agregar_Bahia(CantidadMaximaDePeso, ID_Bahia, Fila_bahia, Columna_Bahia);
					MessageBox::Show("Bahia creada exitosamente");
				}
				else {
					MessageBox::Show("Bahia ya creada anteriormente");
				}
			}
			else if (comboBox1->Text == "Agregar Bahias y Productos") {
				int CantidadMaximaDePeso = Convert::ToInt16(Peso_Maximo_Nueva_Bahia->Text);
				int ID_Bahia;
				if (Id_Bahia_Nueva_1->Checked && Id_Bahia_Nueva_2->Checked && Id_Bahia_Nueva_3->Checked) {
					ID_Bahia = 4;
				}
				else if (Id_Bahia_Nueva_1->Checked && Id_Bahia_Nueva_2->Checked) {
					ID_Bahia = 5;
				}
				else if (Id_Bahia_Nueva_2->Checked && Id_Bahia_Nueva_3->Checked) {
					ID_Bahia = 6;
				}
				else if (Id_Bahia_Nueva_1->Checked && Id_Bahia_Nueva_3->Checked) {
					ID_Bahia = 7;
				}
				else if (Id_Bahia_Nueva_1->Checked)
					ID_Bahia = 1;
				else if (Id_Bahia_Nueva_2->Checked)
					ID_Bahia = 2;
				else if (Id_Bahia_Nueva_3->Checked)
					ID_Bahia = 3;
				else {
					ID_Bahia = 4;
					MessageBox::Show("Ya que no ingreso ningun tipo la Bahia procedera a ser de tipo 4(todo tipo de producto)");
				}
				char Fila_bahia = Convert::ToChar(Ubicacion_Fila->Text);
				int Columna_Bahia = Convert::ToInt16(Ubicacion_Columna->Text);

				Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Fila_bahia, Columna_Bahia);
				if (B1 == nullptr) {
					BodegaPricipal->Agregar_Bahia(CantidadMaximaDePeso, ID_Bahia, Fila_bahia, Columna_Bahia);

					if (Cantidad_Productos->Text != "") {
						int cantidad_de_productos = Convert::ToInt16(Cantidad_Productos->Text);
						Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Fila_bahia, Columna_Bahia);
						for (int i = 1; i <= cantidad_de_productos; i++)
						{
							dia = DateTime::Now;
							Producto^ P1 = gcnew Producto(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text), Nombre_Ingreso->Text, Convert::ToString(dia));
							if (B1 == nullptr) {
								MessageBox::Show("Se pudieron ingrsar " + i + " productos, faltaron " + (cantidad_de_productos - i) + "productos");
								break;
							}
							if (!B1->IngresarProducto(P1)) {
								B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
								if (B1 == nullptr) {
									MessageBox::Show("Se pudieron ingrsar " + i + " productos, faltaron " + (cantidad_de_productos - i) + "productos");
									break;
								}
								B1->IngresarProducto(P1);
								Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Fila_bahia, Columna_Bahia);
							}
						}
					}
					else {
						if (Fila_Producto->Text == "" || Columna_Producto->Text == "") {
							Bahia^ B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
							Producto^ P1 = gcnew Producto(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text), Nombre_Ingreso->Text, Convert::ToString(dia));
							if (!B1->IngresarProducto(P1)) {
								B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
								if (B1 == nullptr) {
									MessageBox::Show("No se pudieron ingrsar Por falta de Bahias de este tipo");
								}
								else {
									B1->IngresarProducto(P1);
								}
							}
							else if (B1 == nullptr) {
								MessageBox::Show("No se pudieron ingrsar Por falta de Bahias de este tipo");
							}
						}
						else {
							Bahia^ B1 = BodegaPricipal->Busqueda_Por_Posicion(Convert::ToChar(Fila_Producto->Text), Convert::ToInt16(Columna_Producto->Text));
							Producto^ P1 = gcnew Producto(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text), Nombre_Ingreso->Text, Convert::ToString(dia));
							if (!B1->IngresarProducto(P1)) {
								B1 = BodegaPricipal->Busqueda_Por_Espacio(Convert::ToInt16(Id_Producto->Text), Convert::ToInt16(Peso_Producto->Text));
								if (B1 == nullptr) {
									MessageBox::Show("No se pudo ingrsar.\nBahias sin espacio para este articulo");
								}
								else {
									B1->IngresarProducto(P1);
								}
							}
						}
					}
					MessageBox::Show("Bahiacreada exitosamente");
				}
				else {
					MessageBox::Show("Bahia ya creada anteriormente");
				}
			}
		}
		catch (...)
		{
			MessageBox::Show("Ocurrio un error inesperado");
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		BodegaInfo->Text = BodegaPricipal->Retornar_Informacion();
	}
	private: System::Void Buscar_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Almacenar_Info != nullptr) {
			Almacenar_Info = nullptr;
		}
		char FilaPosicion;
		int ColumnaPosicion;
		try {
			FilaPosicion = Convert::ToChar(Fila_Bahia_Buscar->Text);
			ColumnaPosicion = Convert::ToInt16(Columna_Bahia_Buscar->Text);
		}
		catch (...) {
			MessageBox::Show("Ingreso Un dato que no se puede utilizar.");
		}
		if (FilaPosicion != NULL && ColumnaPosicion != NULL) {
			Almacenar_Info = BodegaPricipal->Busqueda_Por_Posicion(FilaPosicion, ColumnaPosicion);
			if (Almacenar_Info != nullptr){
				String^ informacion = Almacenar_Info->Retornar_Informacion();
				Bahia_Encontrada->Text = informacion;
				informacion = Almacenar_Info->Retornar_Informacion_Productos();
				Productos_Encontrados->Text = informacion;
			}
			else {
				MessageBox::Show("Bahia inexistente.");
			}


		}
	}
	private: System::Void Eliminar_Bahia_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Almacenar_Info == nullptr) {
			MessageBox::Show("Busque una bahia.");
		}
		else {
			if (Almacenar_Info->BahiaActiva.Cabeza != nullptr) {
				int Contador_Productos = Almacenar_Info->Retornar_Cantidad_Productos();
				for (int i = 0; i < Contador_Productos; i++) {
					Producto^ Mover = Almacenar_Info->Retornar_Primer_Producto();
					Bahia^ B1 = BodegaPricipal->Busqueda_Por_Espacio_2(Convert::ToInt16(Mover->Retornar_Id()), Convert::ToInt16(Mover->Retornar_Peso()), Almacenar_Info->Retornar_Ubicacion_Columna(), Almacenar_Info->Retornar_Ubicacion_Fila());
					if (B1 == nullptr) {
						MessageBox::Show("Se pudieron Mover " + i + " productos, faltaron " + (Contador_Productos - i) + " productos\nNo se pudo eliminar");
						break;
					}
					if (B1->IngresarProducto(Mover))
					{
						Almacenar_Info->SacarProductoEspecifico(Mover->Retornar_Id());
					}
				}
				if (Almacenar_Info->BahiaActiva.Cabeza == nullptr) {
					BodegaPricipal->Eliminar_Bahia(Almacenar_Info);
					MessageBox::Show("Bahia " + Convert::ToString(Almacenar_Info->Retornar_Ubicacion_Columna()) + "," + Convert::ToString(Almacenar_Info->Retornar_Ubicacion_Fila()) + " Eliminada");
				}
			}
			else {
				BodegaPricipal->Eliminar_Bahia(Almacenar_Info);
				MessageBox::Show("Bahia " + Convert::ToString(Almacenar_Info->Retornar_Ubicacion_Columna()) + "," + Convert::ToString(Almacenar_Info->Retornar_Ubicacion_Fila()) + " Eliminada");
			}
		}
	}
	private: System::Void Buscar_Producto_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			int ID_Bahia;
			int Cantidad_De_Unidade = Convert::ToInt16(Cantidad_Sacar_Unidades->Text);
			char FilaBuscarP = Convert::ToChar(Fila_Bahia_P->Text);
			int ColumnaBuscarP = Convert::ToInt16(Columna_Bahia_P->Text);
			if (ID_1_Producto_Buscando->Checked)
			ID_Bahia = 1;
			else if (ID_2_Producto_Buscando->Checked)
			ID_Bahia = 2;
			else if (ID_3_Producto_Buscando->Checked)
			ID_Bahia = 3;

			Almacenar_Info = BodegaPricipal->Busqueda_Por_ID(ColumnaBuscarP, FilaBuscarP);
			textBox1->Text = Almacenar_Info->Retornar_Informacion_Producto(ID_Bahia);

		}
		catch (...) {

		}
	}
	private: System::Void Eliminar_Producto_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			int ID_Bahia;
			int Cantidad_De_Unidade = Convert::ToInt16(Cantidad_Sacar_Unidades->Text);
			char FilaBuscarP;
			int ColumnaBuscarP;
			if (ID_1_Producto_Buscando->Checked)
				ID_Bahia = 1;
			else if (ID_2_Producto_Buscando->Checked)
				ID_Bahia = 2;
			else if (ID_3_Producto_Buscando->Checked)
				ID_Bahia = 3;

			if ("" != Fila_Bahia_P->Text && Columna_Bahia_P->Text != "") {
				FilaBuscarP = Convert::ToChar(Fila_Bahia_P->Text);
				ColumnaBuscarP = Convert::ToInt16(Columna_Bahia_P->Text);
				Almacenar_Info = BodegaPricipal->Busqueda_Por_Posicion(FilaBuscarP, ColumnaBuscarP);
			}
			else {
				Almacenar_Info = BodegaPricipal->Busqueda_Por_ID(ID_Bahia, 65);
			}
			try {

				textBox1->Text = Almacenar_Info->Retornar_Informacion_Producto(ID_Bahia);
			}
			catch (...) {

			}
			for (int i = 0; i < Cantidad_De_Unidade; i++)
			{
				Almacenar_Info->SacarProductoEspecifico(ID_Bahia);
			}
		}
		catch (...) {

		}
	}
private: System::Void ID_1_Producto_Buscando_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (ID_1_Producto_Buscando->Checked == true)
	{
		ID_2_Producto_Buscando->Visible = false;
		ID_3_Producto_Buscando->Visible = false;
	}
	else {
		ID_2_Producto_Buscando->Visible = true;
		ID_3_Producto_Buscando->Visible = true;
	}
}
private: System::Void ID_2_Producto_Buscando_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (ID_2_Producto_Buscando->Checked == true)
	{
		ID_1_Producto_Buscando->Visible = false;
		ID_3_Producto_Buscando->Visible = false;
	}
	else {
		ID_1_Producto_Buscando->Visible = true;
		ID_3_Producto_Buscando->Visible = true;
	}
}
private: System::Void ID_3_Producto_Buscando_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (ID_3_Producto_Buscando->Checked == true)
	{
		ID_1_Producto_Buscando->Visible = false;
		ID_2_Producto_Buscando->Visible = false;
	}
	else {
		ID_1_Producto_Buscando->Visible = true;
		ID_2_Producto_Buscando->Visible = true;
	}
}
};
}
