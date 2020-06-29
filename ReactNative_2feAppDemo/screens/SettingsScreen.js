import React from 'react';
import { StyleSheet, Text,  Image, KeyboardAvoidingView } from 'react-native';
import { Button,  Container, Content, Card,
CardItem, Item, Input, Picker} from  'native-base'
import Icon from 'react-native-vector-icons/FontAwesome';
import posed from 'react-native-pose';
import MyHeader from './MyHeader';


const FadeInAnim = posed.View({
  visible: {
    opacity: 1,
    transition: { duration: 700 }
  },
  hidden: {
    opacity: 0,
    transition: { duration: 700 }
  }});

  const BoopAnim = posed.View({
    booped: {
      scale: 0.9,
      transition: { type: 'spring', stiffness: 100, duration: 50 }
    },
    unbooped: {
      scale: 1,
      transition: { type: 'spring', stiffness: 100, duration: 50 }
    }
  });

class SettingsScreen extends React.Component {
  static navigationOptions = {
    drawerIcon: ({tintColor}) =>
        <Icon name = "cog" style = {{fontSize:24, color: tintColor}}/>,
        drawerLabel: "Настройки"
  }

  constructor(props){
    super(props);
    this.state = {
      username : "Пользователь",
      email: "user@user.com",
      phone: "+79998886677",
      city: undefined,
      text: 'Сохранить',
      backgroundColor: '#5b6be8'
    };  
  }

  onValueChange(value: string) {
    this.setState({
      city: value
    });
  }

  
  _onContentSizeChange = ({nativeEvent:event}) => {
    this.setState({ textareaHeight: event.contentSize.height });
  }

  state = { isVisible: true, isBooped: false, backgroundColor: '#5b6be8', text: 'Сохранить'};

  componentDidMount() {
      this.setState({ isVisible: !this.state.isVisible});
    }

  boopTheButton(){
    this.setState({isBooped: !this.state.isBooped});
    if(this.state.isBooped){
      this.setState({backgroundColor: "#5b6be8", text: 'Сохранить'});

    } else{
      this.setState({backgroundColor: "grey", text: 'Сохранено'}); 
    }

  }
  

  render() {
 

    const { isVisible } = this.state;
    const { isBooped } = this.state;

    return (
      <Container>
          <MyHeader />
           <KeyboardAvoidingView style={styles.container} behavior="padding" enabled>
    
           <FadeInAnim pose={this.state.isVisible ? 'visible' : 'hidden'}>
          <Content ref={c => (this.component = c)}>
          <Card>
          <CardItem>
   
            <Image source={require('../assets/user.png')} style = {{width: 100, height: 100, resizeMode: 'contain'}}/>

            <Text style = {{color: "#2196f3", fontSize:15, marginLeft: 15}}>Выбрать фото</Text>

             </CardItem>
     
            <CardItem>
            <Item>
            <Icon active name='user' style = {{fontSize: 20, color: "#5b6be8",margin:5}}/>
            <Input placeholder='Эл. почта' defaultValue = {this.state.username} onChangeText={(username) => this.setState({username})}
          />  
            </Item>
             </CardItem>
             <CardItem>
             <Item>
            <Icon active name='inbox' style = {{fontSize: 20, color: "#5b6be8",margin:5}}/>
            <Input keyboardType='email-address' placeholder='Эл. почта' defaultValue = {this.state.email} onChangeText={(email) => this.setState({email})}
             />  
            </Item>
            </CardItem>
            <CardItem>
            <Item picker>
            <Picker
                mode="dropdown"
                iosIcon={<Icon name="arrow-down" />}
                style={{ width: undefined }}
                placeholder="Select your SIM"
                placeholderStyle={{ color: "#bfc6ea" }}
                placeholderIconColor="#007aff"
                selectedValue={this.state.city}
                onValueChange={this.onValueChange.bind(this)}
              >
                <Picker.Item  label="Владивосток" value="key0" />
                <Picker.Item  label="Артем" value="key1" />
                </Picker>
            </Item>
             </CardItem>
            <CardItem>
            <Item >
            <Icon active  name='phone' style = {{fontSize: 20, color: "#5b6be8",margin:5}}/>
            <Input keyboardType='phone-pad' placeholder='Телефон' defaultValue = {this.state.phone} onChangeText={(phone) => this.setState({phone})}
              value={this.state.phone}  onContentSizeChange={this._onContentSizeChange}/>  
            </Item>
             </CardItem>

          <CardItem style = {{alignItems:'center',justifyContent:'center'}}>
               <BoopAnim pose={this.state.isBooped ? 'booped' : 'unbooped'}>
               <Button block style = {{backgroundColor: this.state.backgroundColor, width: 300}} onPress = {()=>this.boopTheButton()} >
               <Text style = {{color: 'white', fontSize: 16}}>{this.state.text}</Text>
               </Button>
               </BoopAnim>
            </CardItem>  

              </Card>
              </Content>
              </FadeInAnim>
             </KeyboardAvoidingView>
            </Container>
     

    );
  }

}

export default SettingsScreen;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
