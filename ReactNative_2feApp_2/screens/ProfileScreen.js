import React from 'react';
import { StyleSheet, Text, Image} from 'react-native';
import { Button, Container, Content,
Card, CardItem, Toast} from  'native-base'
import Icon from 'react-native-vector-icons/FontAwesome';
import MyHeader from './MyHeader';
import posed from 'react-native-pose';


const FadeInAnim = posed.View({
  visible: {
    opacity: 1,
    transition: { duration: 700 }
  },
  hidden: {
    opacity: 0,
    transition: { duration: 700 }
  }});

class SettingsScreen extends React.Component {
  static navigationOptions = {
    drawerLabel: ()=>null
  }

  state = { isVisible: false};

  componentDidMount() {
      this.setState({ isVisible: !this.state.isVisible});
    }

  
  render() {
  
    const { isVisible } = this.state;

    return (
      <Container>

      <MyHeader />
          <Content ref={c => (this.component = c)}>
          <FadeInAnim pose={this.state.isVisible ? 'visible' : 'hidden'}>
          <Card>
            <CardItem style = {{flex:1,flexDirection: 'column',alignItems:'center', justifyContent:'center'}}>
            <Image source = {require('../assets/user.png')}
          style = {{width: 200, height: 200, resizeMode: 'contain'}}></Image>
          <Text style = {{fontSize: 21}}>Пользователь</Text>

         <Text style = {{fontSize: 15}}>Баланс: 500₽</Text>

          
    
          <Button block style = {{margin: 5, marginTop:15, backgroundColor: "#3cab94"}} onPress = {()=>this.props.navigation.navigate('MyCoupons')}>
          <Icon style = {{fontSize: 18, color: 'white', padding: 5}} name = "tags"></Icon>
          <Text style = {{fontSize: 15, color: 'white'}}>Мои купоны</Text>
            </Button>

          <Button block style = {{margin: 5, backgroundColor: "#5b6be8"}} onPress = {()=>this.props.navigation.navigate('Settings')}>
          <Icon style = {{fontSize: 18, color: 'white', padding: 5}} name = "cog"></Icon>
          <Text style = {{fontSize: 15, color: 'white'}}>Настройки</Text>
          </Button>

          <Button block style = {{margin: 5, backgroundColor: "#d8933a"}} onPress = {() => Toast.show({
          text: "Вжух! Баланс пополнен.",
          buttonText: "ееее бои",
          type: "warning",
          duration: 5000
        })}>
          <Icon style = {{fontSize: 18, color: 'white', padding: 5}} name = "money"></Icon>
          <Text style = {{fontSize: 15, color: 'white'}}>Пополнить баланс</Text>
          </Button>
            </CardItem>
            </Card>
            </FadeInAnim>
              </Content>
       
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
