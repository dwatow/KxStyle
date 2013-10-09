#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>
#using <System.Data.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
// 
// 此原始程式碼由 xsd 版本=2.0.50727.42 自動產生。
// 
namespace PatternContruction {
    
    using namespace System;
    ref class DataSet1;
    
    
    /// <summary>
///Represents a strongly typed in-memory cache of data.
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0"), 
    System::Serializable, 
    System::ComponentModel::DesignerCategoryAttribute(L"code"), 
    System::ComponentModel::ToolboxItem(true), 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedDataSetSchema"), 
    System::Xml::Serialization::XmlRootAttribute(L"DataSet1"), 
    System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.DataSet")]
    public ref class DataSet1 : public ::System::Data::DataSet {
        public : ref class DataTable1DataTable;
        public : ref class DataTable1Row;
        public : ref class DataTable1RowChangeEvent;
        
        private: PatternContruction::DataSet1::DataTable1DataTable^  tableDataTable1;
        
        private: ::System::Data::SchemaSerializationMode _schemaSerializationMode;
        
        public : delegate System::Void DataTable1RowChangeEventHandler(::System::Object^  sender, PatternContruction::DataSet1::DataTable1RowChangeEvent^  e);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        DataSet1();
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        DataSet1(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::Browsable(false), 
        System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
        property PatternContruction::DataSet1::DataTable1DataTable^  DataTable1 {
            PatternContruction::DataSet1::DataTable1DataTable^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::BrowsableAttribute(true), 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Visible)]
        virtual property ::System::Data::SchemaSerializationMode SchemaSerializationMode {
            ::System::Data::SchemaSerializationMode get() override;
            System::Void set(::System::Data::SchemaSerializationMode value) override;
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
        property ::System::Data::DataTableCollection^  Tables {
            ::System::Data::DataTableCollection^  get() new;
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
        property ::System::Data::DataRelationCollection^  Relations {
            ::System::Data::DataRelationCollection^  get() new;
        }
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Void InitializeDerivedDataSet() override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Data::DataSet^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Boolean ShouldSerializeTables() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Boolean ShouldSerializeRelations() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Void ReadXmlSerializable(::System::Xml::XmlReader^  reader) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Xml::Schema::XmlSchema^  GetSchemaSerializable() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitVars();
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitVars(::System::Boolean initTable);
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitClass();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Boolean ShouldSerializeDataTable1();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        
        /// <summary>
///Represents the strongly named DataTable class.
///</summary>
        public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0"), 
        System::Serializable, 
        System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
        ref class DataTable1DataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
            
            private: ::System::Data::DataColumn^  columnid;
            
            public: event PatternContruction::DataSet1::DataTable1RowChangeEventHandler^  DataTable1RowChanging;
            
            public: event PatternContruction::DataSet1::DataTable1RowChangeEventHandler^  DataTable1RowChanged;
            
            public: event PatternContruction::DataSet1::DataTable1RowChangeEventHandler^  DataTable1RowDeleting;
            
            public: event PatternContruction::DataSet1::DataTable1RowChangeEventHandler^  DataTable1RowDeleted;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            DataTable1DataTable();
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            DataTable1DataTable(::System::Data::DataTable^  table);
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            DataTable1DataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  idColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::ComponentModel::Browsable(false)]
            property ::System::Int32 Count {
                ::System::Int32 get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property PatternContruction::DataSet1::DataTable1Row^  default [::System::Int32 ] {
                PatternContruction::DataSet1::DataTable1Row^  get(::System::Int32 index);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void AddDataTable1Row(PatternContruction::DataSet1::DataTable1Row^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            PatternContruction::DataSet1::DataTable1Row^  AddDataTable1Row(System::Double id);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Collections::IEnumerator^  GetEnumerator();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  Clone() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  CreateInstance() override;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitVars();
            
            private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitClass();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            PatternContruction::DataSet1::DataTable1Row^  NewDataTable1Row();
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Type^  GetRowType() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void RemoveDataTable1Row(PatternContruction::DataSet1::DataTable1Row^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        };
        
        /// <summary>
///Represents strongly named DataRow class.
///</summary>
        public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class DataTable1Row : public ::System::Data::DataRow {
            
            private: PatternContruction::DataSet1::DataTable1DataTable^  tableDataTable1;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            DataTable1Row(::System::Data::DataRowBuilder^  rb);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::Double id {
                System::Double get();
                System::Void set(System::Double value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Boolean IsidNull();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void SetidNull();
        };
        
        /// <summary>
///Row event argument class
///</summary>
        public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class DataTable1RowChangeEvent : public ::System::EventArgs {
            
            private: PatternContruction::DataSet1::DataTable1Row^  eventRow;
            
            private: ::System::Data::DataRowAction eventAction;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            DataTable1RowChangeEvent(PatternContruction::DataSet1::DataTable1Row^  row, ::System::Data::DataRowAction action);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property PatternContruction::DataSet1::DataTable1Row^  Row {
                PatternContruction::DataSet1::DataTable1Row^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataRowAction Action {
                ::System::Data::DataRowAction get();
            }
        };
    };
}
namespace PatternContruction {
    
    
    inline DataSet1::DataSet1() {
        this->BeginInit();
        this->InitClass();
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &PatternContruction::DataSet1::SchemaChanged);
        __super::Tables->CollectionChanged += schemaChangedHandler;
        __super::Relations->CollectionChanged += schemaChangedHandler;
        this->EndInit();
    }
    
    inline DataSet1::DataSet1(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataSet(info, context, false) {
        if (this->IsBinarySerialized(info, context) == true) {
            this->InitVars(false);
            ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler1 = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &PatternContruction::DataSet1::SchemaChanged);
            this->Tables->CollectionChanged += schemaChangedHandler1;
            this->Relations->CollectionChanged += schemaChangedHandler1;
            return;
        }
        ::System::String^  strSchema = (cli::safe_cast<::System::String^  >(info->GetValue(L"XmlSchema", ::System::String::typeid)));
        if (this->DetermineSchemaSerializationMode(info, context) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
            ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
            ds->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
            if (ds->Tables[L"DataTable1"] != nullptr) {
                __super::Tables->Add((gcnew PatternContruction::DataSet1::DataTable1DataTable(ds->Tables[L"DataTable1"])));
            }
            this->DataSetName = ds->DataSetName;
            this->Prefix = ds->Prefix;
            this->Namespace = ds->Namespace;
            this->Locale = ds->Locale;
            this->CaseSensitive = ds->CaseSensitive;
            this->EnforceConstraints = ds->EnforceConstraints;
            this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
            this->InitVars();
        }
        else {
            this->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
        }
        this->GetSerializationData(info, context);
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &PatternContruction::DataSet1::SchemaChanged);
        __super::Tables->CollectionChanged += schemaChangedHandler;
        this->Relations->CollectionChanged += schemaChangedHandler;
    }
    
    inline PatternContruction::DataSet1::DataTable1DataTable^  DataSet1::DataTable1::get() {
        return this->tableDataTable1;
    }
    
    inline ::System::Data::SchemaSerializationMode DataSet1::SchemaSerializationMode::get() {
        return this->_schemaSerializationMode;
    }
    inline System::Void DataSet1::SchemaSerializationMode::set(::System::Data::SchemaSerializationMode value) {
        this->_schemaSerializationMode = __identifier(value);
    }
    
    inline ::System::Data::DataTableCollection^  DataSet1::Tables::get() {
        return __super::Tables;
    }
    
    inline ::System::Data::DataRelationCollection^  DataSet1::Relations::get() {
        return __super::Relations;
    }
    
    inline ::System::Void DataSet1::InitializeDerivedDataSet() {
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline ::System::Data::DataSet^  DataSet1::Clone() {
        PatternContruction::DataSet1^  cln = (cli::safe_cast<PatternContruction::DataSet1^  >(__super::Clone()));
        cln->InitVars();
        cln->SchemaSerializationMode = this->SchemaSerializationMode;
        return cln;
    }
    
    inline ::System::Boolean DataSet1::ShouldSerializeTables() {
        return false;
    }
    
    inline ::System::Boolean DataSet1::ShouldSerializeRelations() {
        return false;
    }
    
    inline ::System::Void DataSet1::ReadXmlSerializable(::System::Xml::XmlReader^  reader) {
        if (this->DetermineSchemaSerializationMode(reader) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
            this->Reset();
            ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
            ds->ReadXml(reader);
            if (ds->Tables[L"DataTable1"] != nullptr) {
                __super::Tables->Add((gcnew PatternContruction::DataSet1::DataTable1DataTable(ds->Tables[L"DataTable1"])));
            }
            this->DataSetName = ds->DataSetName;
            this->Prefix = ds->Prefix;
            this->Namespace = ds->Namespace;
            this->Locale = ds->Locale;
            this->CaseSensitive = ds->CaseSensitive;
            this->EnforceConstraints = ds->EnforceConstraints;
            this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
            this->InitVars();
        }
        else {
            this->ReadXml(reader);
            this->InitVars();
        }
    }
    
    inline ::System::Xml::Schema::XmlSchema^  DataSet1::GetSchemaSerializable() {
        ::System::IO::MemoryStream^  stream = (gcnew ::System::IO::MemoryStream());
        this->WriteXmlSchema((gcnew ::System::Xml::XmlTextWriter(stream, nullptr)));
        stream->Position = 0;
        return ::System::Xml::Schema::XmlSchema::Read((gcnew ::System::Xml::XmlTextReader(stream)), nullptr);
    }
    
    inline ::System::Void DataSet1::InitVars() {
        this->InitVars(true);
    }
    
    inline ::System::Void DataSet1::InitVars(::System::Boolean initTable) {
        this->tableDataTable1 = (cli::safe_cast<PatternContruction::DataSet1::DataTable1DataTable^  >(__super::Tables[L"DataTable1"]));
        if (initTable == true) {
            if (this->tableDataTable1 != nullptr) {
                this->tableDataTable1->InitVars();
            }
        }
    }
    
    inline ::System::Void DataSet1::InitClass() {
        this->DataSetName = L"DataSet1";
        this->Prefix = L"";
        this->Namespace = L"http://tempuri.org/DataSet1.xsd";
        this->EnforceConstraints = true;
        this->SchemaSerializationMode = ::System::Data::SchemaSerializationMode::IncludeSchema;
        this->tableDataTable1 = (gcnew PatternContruction::DataSet1::DataTable1DataTable());
        __super::Tables->Add(this->tableDataTable1);
    }
    
    inline ::System::Boolean DataSet1::ShouldSerializeDataTable1() {
        return false;
    }
    
    inline ::System::Void DataSet1::SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e) {
        if (e->Action == ::System::ComponentModel::CollectionChangeAction::Remove) {
            this->InitVars();
        }
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  DataSet1::GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        PatternContruction::DataSet1^  ds = (gcnew PatternContruction::DataSet1());
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        ::System::Xml::Schema::XmlSchemaAny^  any = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any->Namespace = ds->Namespace;
        sequence->Items->Add(any);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline DataSet1::DataTable1DataTable::DataTable1DataTable() {
        this->TableName = L"DataTable1";
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline DataSet1::DataTable1DataTable::DataTable1DataTable(::System::Data::DataTable^  table) {
        this->TableName = table->TableName;
        if (table->CaseSensitive != table->DataSet->CaseSensitive) {
            this->CaseSensitive = table->CaseSensitive;
        }
        if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
            this->Locale = table->Locale;
        }
        if (table->Namespace != table->DataSet->Namespace) {
            this->Namespace = table->Namespace;
        }
        this->Prefix = table->Prefix;
        this->MinimumCapacity = table->MinimumCapacity;
    }
    
    inline DataSet1::DataTable1DataTable::DataTable1DataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
                ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataTable(info, context) {
        this->InitVars();
    }
    
    inline ::System::Data::DataColumn^  DataSet1::DataTable1DataTable::idColumn::get() {
        return this->columnid;
    }
    
    inline ::System::Int32 DataSet1::DataTable1DataTable::Count::get() {
        return this->Rows->Count;
    }
    
    inline PatternContruction::DataSet1::DataTable1Row^  DataSet1::DataTable1DataTable::default::get(::System::Int32 index) {
        return (cli::safe_cast<PatternContruction::DataSet1::DataTable1Row^  >(this->Rows[index]));
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::AddDataTable1Row(PatternContruction::DataSet1::DataTable1Row^  row) {
        this->Rows->Add(row);
    }
    
    inline PatternContruction::DataSet1::DataTable1Row^  DataSet1::DataTable1DataTable::AddDataTable1Row(System::Double id) {
        PatternContruction::DataSet1::DataTable1Row^  rowDataTable1Row = (cli::safe_cast<PatternContruction::DataSet1::DataTable1Row^  >(this->NewRow()));
        cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(1) {id};
        rowDataTable1Row->ItemArray = columnValuesArray;
        this->Rows->Add(rowDataTable1Row);
        return rowDataTable1Row;
    }
    
    inline ::System::Collections::IEnumerator^  DataSet1::DataTable1DataTable::GetEnumerator() {
        return this->Rows->GetEnumerator();
    }
    
    inline ::System::Data::DataTable^  DataSet1::DataTable1DataTable::Clone() {
        PatternContruction::DataSet1::DataTable1DataTable^  cln = (cli::safe_cast<PatternContruction::DataSet1::DataTable1DataTable^  >(__super::Clone()));
        cln->InitVars();
        return cln;
    }
    
    inline ::System::Data::DataTable^  DataSet1::DataTable1DataTable::CreateInstance() {
        return (gcnew PatternContruction::DataSet1::DataTable1DataTable());
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::InitVars() {
        this->columnid = __super::Columns[L"id"];
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::InitClass() {
        this->columnid = (gcnew ::System::Data::DataColumn(L"id", ::System::Double::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnid);
    }
    
    inline PatternContruction::DataSet1::DataTable1Row^  DataSet1::DataTable1DataTable::NewDataTable1Row() {
        return (cli::safe_cast<PatternContruction::DataSet1::DataTable1Row^  >(this->NewRow()));
    }
    
    inline ::System::Data::DataRow^  DataSet1::DataTable1DataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
        return (gcnew PatternContruction::DataSet1::DataTable1Row(builder));
    }
    
    inline ::System::Type^  DataSet1::DataTable1DataTable::GetRowType() {
        return PatternContruction::DataSet1::DataTable1Row::typeid;
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanged(e);
        {
            this->DataTable1RowChanged(this, (gcnew PatternContruction::DataSet1::DataTable1RowChangeEvent((cli::safe_cast<PatternContruction::DataSet1::DataTable1Row^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanging(e);
        {
            this->DataTable1RowChanging(this, (gcnew PatternContruction::DataSet1::DataTable1RowChangeEvent((cli::safe_cast<PatternContruction::DataSet1::DataTable1Row^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleted(e);
        {
            this->DataTable1RowDeleted(this, (gcnew PatternContruction::DataSet1::DataTable1RowChangeEvent((cli::safe_cast<PatternContruction::DataSet1::DataTable1Row^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleting(e);
        {
            this->DataTable1RowDeleting(this, (gcnew PatternContruction::DataSet1::DataTable1RowChangeEvent((cli::safe_cast<PatternContruction::DataSet1::DataTable1Row^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void DataSet1::DataTable1DataTable::RemoveDataTable1Row(PatternContruction::DataSet1::DataTable1Row^  row) {
        this->Rows->Remove(row);
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  DataSet1::DataTable1DataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        PatternContruction::DataSet1^  ds = (gcnew PatternContruction::DataSet1());
        ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
        any1->MinOccurs = ::System::Decimal(0);
        any1->MaxOccurs = ::System::Decimal::MaxValue;
        any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any1);
        ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
        any2->MinOccurs = ::System::Decimal(1);
        any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any2);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute1->Name = L"namespace";
        attribute1->FixedValue = ds->Namespace;
        type->Attributes->Add(attribute1);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute2->Name = L"tableTypeName";
        attribute2->FixedValue = L"DataTable1DataTable";
        type->Attributes->Add(attribute2);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline DataSet1::DataTable1Row::DataTable1Row(::System::Data::DataRowBuilder^  rb) : 
            ::System::Data::DataRow(rb) {
        this->tableDataTable1 = (cli::safe_cast<PatternContruction::DataSet1::DataTable1DataTable^  >(this->Table));
    }
    
    inline System::Double DataSet1::DataTable1Row::id::get() {
        try {
            return (*cli::safe_cast<::System::Double^>(this[this->tableDataTable1->idColumn]));
        }
        catch (::System::InvalidCastException^ e) {
            throw (gcnew ::System::Data::StrongTypingException(L"資料表 \'DataTable1\' 中資料行 \'id\' 的值是 DBNull。", e));
        }
    }
    inline System::Void DataSet1::DataTable1Row::id::set(System::Double value) {
        this[this->tableDataTable1->idColumn] = value;
    }
    
    inline ::System::Boolean DataSet1::DataTable1Row::IsidNull() {
        return this->IsNull(this->tableDataTable1->idColumn);
    }
    
    inline ::System::Void DataSet1::DataTable1Row::SetidNull() {
        this[this->tableDataTable1->idColumn] = ::System::Convert::DBNull;
    }
    
    
    inline DataSet1::DataTable1RowChangeEvent::DataTable1RowChangeEvent(PatternContruction::DataSet1::DataTable1Row^  row, 
                ::System::Data::DataRowAction action) {
        this->eventRow = row;
        this->eventAction = action;
    }
    
    inline PatternContruction::DataSet1::DataTable1Row^  DataSet1::DataTable1RowChangeEvent::Row::get() {
        return this->eventRow;
    }
    
    inline ::System::Data::DataRowAction DataSet1::DataTable1RowChangeEvent::Action::get() {
        return this->eventAction;
    }
}
namespace PatternContruction {
    namespace DataSet1TableAdapters {
    
    using namespace System;
    ref class DataTable1TableAdapter;
    
    
    /// <summary>
///Represents the connection and commands used to retrieve and save data.
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0"), 
    System::ComponentModel::DesignerCategoryAttribute(L"code"), 
    System::ComponentModel::ToolboxItem(true), 
    System::ComponentModel::DataObjectAttribute(true), 
    System::ComponentModel::DesignerAttribute(L"Microsoft.VSDesigner.DataSource.Design.TableAdapterDesigner, Microsoft.VSDesigner" 
L", Version=8.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a"), 
    System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.TableAdapter")]
    public ref class DataTable1TableAdapter : public ::System::ComponentModel::Component {
        
        private: ::System::Data::Odbc::OdbcDataAdapter^  _adapter;
        
        private: ::System::Data::Odbc::OdbcConnection^  _connection;
        
        private: cli::array< ::System::Data::Odbc::OdbcCommand^  >^  _commandCollection;
        
        private: ::System::Boolean _clearBeforeFill;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        DataTable1TableAdapter();
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        property ::System::Data::Odbc::OdbcDataAdapter^  Adapter {
            ::System::Data::Odbc::OdbcDataAdapter^  get();
        }
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        property ::System::Data::Odbc::OdbcConnection^  Connection {
            ::System::Data::Odbc::OdbcConnection^  get();
            System::Void set(::System::Data::Odbc::OdbcConnection^  value);
        }
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        property cli::array< ::System::Data::Odbc::OdbcCommand^  >^  CommandCollection {
            cli::array< ::System::Data::Odbc::OdbcCommand^  >^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        property ::System::Boolean ClearBeforeFill {
            ::System::Boolean get();
            System::Void set(::System::Boolean value);
        }
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitAdapter();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitConnection();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitCommandCollection();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.TableAdapter")]
        [System::ComponentModel::DataObjectMethodAttribute(::System::ComponentModel::DataObjectMethodType::Fill, true)]
        virtual System::Int32 Fill(PatternContruction::DataSet1::DataTable1DataTable^  dataTable);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.TableAdapter")]
        [System::ComponentModel::DataObjectMethodAttribute(::System::ComponentModel::DataObjectMethodType::Select, true)]
        virtual PatternContruction::DataSet1::DataTable1DataTable^  GetData();
    };
    }
}
namespace PatternContruction {
    namespace DataSet1TableAdapters {
    
    
    inline DataTable1TableAdapter::DataTable1TableAdapter() {
        this->ClearBeforeFill = true;
    }
    
    inline ::System::Data::Odbc::OdbcDataAdapter^  DataTable1TableAdapter::Adapter::get() {
        if (this->_adapter == nullptr) {
            this->InitAdapter();
        }
        return this->_adapter;
    }
    
    inline ::System::Data::Odbc::OdbcConnection^  DataTable1TableAdapter::Connection::get() {
        if (this->_connection == nullptr) {
            this->InitConnection();
        }
        return this->_connection;
    }
    inline System::Void DataTable1TableAdapter::Connection::set(::System::Data::Odbc::OdbcConnection^  value) {
        this->_connection = __identifier(value);
        if (this->Adapter->InsertCommand != nullptr) {
            this->Adapter->InsertCommand->Connection = __identifier(value);
        }
        if (this->Adapter->DeleteCommand != nullptr) {
            this->Adapter->DeleteCommand->Connection = __identifier(value);
        }
        if (this->Adapter->UpdateCommand != nullptr) {
            this->Adapter->UpdateCommand->Connection = __identifier(value);
        }
        for (        ::System::Int32 i = 0; (i < this->CommandCollection->Length);         i = (i + 1)) {
            if (this->CommandCollection[i] != nullptr) {
                (cli::safe_cast<::System::Data::Odbc::OdbcCommand^  >(this->CommandCollection[i]))->Connection = __identifier(value);
            }
        }
    }
    
    inline cli::array< ::System::Data::Odbc::OdbcCommand^  >^  DataTable1TableAdapter::CommandCollection::get() {
        if (this->_commandCollection == nullptr) {
            this->InitCommandCollection();
        }
        return this->_commandCollection;
    }
    
    inline ::System::Boolean DataTable1TableAdapter::ClearBeforeFill::get() {
        return this->_clearBeforeFill;
    }
    inline System::Void DataTable1TableAdapter::ClearBeforeFill::set(::System::Boolean value) {
        this->_clearBeforeFill = __identifier(value);
    }
    
    inline ::System::Void DataTable1TableAdapter::InitAdapter() {
        this->_adapter = (gcnew ::System::Data::Odbc::OdbcDataAdapter());
        ::System::Data::Common::DataTableMapping^  tableMapping = (gcnew ::System::Data::Common::DataTableMapping());
        tableMapping->SourceTable = L"Table";
        tableMapping->DataSetTable = L"DataTable1";
        tableMapping->ColumnMappings->Add(L"id", L"id");
        this->_adapter->TableMappings->Add(tableMapping);
    }
    
    inline ::System::Void DataTable1TableAdapter::InitConnection() {
        this->_connection = (gcnew ::System::Data::Odbc::OdbcConnection());
        this->_connection->ConnectionString = L"Dsn=Excel Files;dbq=E:\\DataBase.xls;defaultdir=E:;driverid=790;maxbuffersize=2048" 
L";pagetimeout=5";
    }
    
    inline ::System::Void DataTable1TableAdapter::InitCommandCollection() {
        this->_commandCollection = gcnew cli::array< ::System::Data::Odbc::OdbcCommand^  >(1);
        this->_commandCollection[0] = (gcnew ::System::Data::Odbc::OdbcCommand());
        this->_commandCollection[0]->Connection = this->Connection;
        this->_commandCollection[0]->CommandText = L"SELECT         id\r\nFROM     [ExcelData$]             \r\nORDER BY  id";
        this->_commandCollection[0]->CommandType = ::System::Data::CommandType::Text;
    }
    
    inline System::Int32 DataTable1TableAdapter::Fill(PatternContruction::DataSet1::DataTable1DataTable^  dataTable) {
        this->Adapter->SelectCommand = this->CommandCollection[0];
        if (this->ClearBeforeFill == true) {
            dataTable->Clear();
        }
        ::System::Int32 returnValue = this->Adapter->Fill(dataTable);
        return returnValue;
    }
    
    inline PatternContruction::DataSet1::DataTable1DataTable^  DataTable1TableAdapter::GetData() {
        this->Adapter->SelectCommand = this->CommandCollection[0];
        PatternContruction::DataSet1::DataTable1DataTable^  dataTable = (gcnew PatternContruction::DataSet1::DataTable1DataTable());
        this->Adapter->Fill(dataTable);
        return dataTable;
    }
    }
}
