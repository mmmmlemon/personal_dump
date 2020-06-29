import React from 'react';
import { StyleSheet, Text, View, Image} from 'react-native';
import { Left, Body,
    Content, Card, CardItem, Thumbnail, Container} from  'native-base'
import Icon from 'react-native-vector-icons/FontAwesome';
import MyHeader from './MyHeader';


class NewsCard extends React.Component{
  render(){
    return(
      <Card>
      <CardItem>
        <Left>
            <Body>     
            <Text style = {{fontSize: 18}}>{this.props.newsTitle}</Text>
            <Text style = {{paddingTop: 5, color: 'grey'}}>{this.props.date}</Text>
          </Body>
        </Left>
      </CardItem>
      <CardItem cardBody>
        <Image source={this.props.image} style={{height: 200, width: null, flex: 1}}/>
      </CardItem>
      <CardItem>
        <Text>{this.props.description}</Text>
      </CardItem>
    </Card>
    );
  }
}



class NewsScreen extends React.Component {
  static navigationOptions = {
    drawerIcon: ({tintColor}) =>
        <Icon name = "newspaper-o" style = {{fontSize:24, color: tintColor}}/>,
        drawerLabel: "Новости"
  }
  render() {
    return (
      <Container>
  <MyHeader headerTitle = "Новости"/>
      <Content ref={c => (this.component = c)}>

            <NewsCard newsTitle = "Срочные новости. Разработчики 'Двафи' уронили сосиску." 
            date = "31.12.2018"
            image = {require('../assets/news1.jpg')}
            description = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed 
            do eiusmod tempor incididunt ut labore et dolore magna aliqua. 
            Ut enim ad minim veniam, quis nostrud exercitation ullamco 
            laboris nisi ut aliquip ex ea commodo consequat. "/>

            <NewsCard newsTitle = "Ого. Еще одна новость." 
            date = "29.12.2018"
            image = {require('../assets/news2.jpg')}
            description = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed 
            do eiusmod tempor incididunt ut labore et dolore magna aliqua. 
            Ut enim ad minim veniam, quis nostrud exercitation ullamco 
            laboris nisi ut aliquip ex ea commodo consequat. "/>

          <NewsCard newsTitle = "И еще одна." 
            date = "28.12.2018"
            image = {require('../assets/news3.jpg')}
            description = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed 
            do eiusmod tempor incididunt ut labore et dolore magna aliqua. 
            Ut enim ad minim veniam, quis nostrud exercitation ullamco 
            laboris nisi ut aliquip ex ea commodo consequat. "/>

            
          <NewsCard newsTitle = "Вот и все, ребята." 
            date = "28.12.2018"
            image = {require('../assets/news4.jpg')}
            description = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed 
            do eiusmod tempor incididunt ut labore et dolore magna aliqua. 
            Ut enim ad minim veniam, quis nostrud exercitation ullamco 
            laboris nisi ut aliquip ex ea commodo consequat. "/>


            <View style = {{justifyContent: 'center',alignItems: 'center' }}>
            <Icon name = "arrow-up" style = {{fontSize: 25, padding:5, color: "#5b6be8"}} onPress={() => this.component._root.scrollToPosition(0, 0)}></Icon>
            <Text style = {{padding: 5, fontSize: 18, color: "#5b6be8"}}>Больше ничего нет :(</Text>
            </View>
        
          </Content>
   
        </Container>
    );
  }
}

export default NewsScreen;



const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
